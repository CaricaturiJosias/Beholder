//
// cliente da aplicação Beholder
//

#include <iostream>
#include <string>
#include "../idl/BeholderC.h"

// GSOAP
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/bhldr.nsmap" // include XML namespaces

#include "gsoap/plugin/threads.h"
#include "gsoap/plugin/httpget.h"

// Beholder
#include <Beholder/pugixml.hpp>
// #include <Beholder/SchemaUtils.hxx>

using namespace std;
using namespace DSMComms;

// So we can contact the server on the SOAP requests
POA_Beholder_var Beholder;

int port = 12332; //  Port number we are using

void *process_request(void *arg)
{
  struct soap *service = (soap*)arg;
  THREAD_DETACH(THREAD_ID);
  if (service)
  {
    soap_serve(service);
    service->destroy(); /* clean up */
    delete service;
  }
  return NULL;
}


int http_get_handler(struct soap *soap) {
	// Straight from https://www.genivia.com/tutorials.html
	// Made by genivia
	FILE *fd;
  	char *s = strchr(soap->path, '?'); // soap->path has the URL path (soap->endpoint has the full URL)
  	if (!s || strcmp(s, "?wsdl")) 
  	  return SOAP_GET_METHOD; // GET method not supported
  	fd = fopen("bhldr.wsdl", "rb"); // open WSDL file to copy as a response
  	if (!fd) {
		std::cout << "COULD NOT READ FILE " << std::endl;
		return 404; // return HTTP 404 not found
	}
  	soap->http_content = "text/xml; charset=utf-8"; // HTTP header with text/xml content 
  	// send http header 200 OK and the XML response
  	if (soap_response(soap, SOAP_FILE))
  	{
		fclose(fd);
		return soap_closesock(soap);
  	}
  	for (;;) 
  	{
		size_t r = fread(soap->tmpbuf, 1, sizeof(soap->tmpbuf), fd); 
		if (!r || soap_send_raw(soap, soap->tmpbuf, r)) 
			break;
  	} 
  	fclose(fd); 
  	soap_end_send(soap); 
  	return SOAP_OK; 
}

int main(int argc, char* argv[])
{

	try {
		// 1. Initiate ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc,argv,"ORB");

		// 2. Obtain object reference
		CORBA::Object_ptr tmp_ref;

		tmp_ref = orb->string_to_object("file://teste");
		Beholder = POA_Beholder::_narrow(tmp_ref);

		// 3. Use Beholder
		cout << "starting soap" << endl;
		struct soap *soap = soap_new1(SOAP_IO_KEEPALIVE); 
		soap->fget = http_get_handler;
		soap->send_timeout = soap->recv_timeout = 5; /* 5 sec socket idle timeout */
  		soap->transfer_timeout = 30;  /* 30 sec message transfer timeout */   
  		SOAP_SOCKET m = soap_bind(soap, NULL, port, 100);              /* master socket */
		if (soap_valid_socket(m))
		{
			while (soap_valid_socket(soap_accept(soap)))
			{
			THREAD_TYPE tid;
			void *arg = (void*)soap_copy(soap);
			/* use updated THREAD_CREATE from plugin/threads.h https://www.genivia.com/files/threads.zip */
			if (arg)
				while (THREAD_CREATE(&tid, (void*(*)(void*))process_request, arg))
				sleep(1);
			}
		}
		// struct soap * soap = soap_new();
		soap_serve(soap);
		soap->destroy(); /* clean up */
		soap_end(soap);
		soap_free(soap);
		// 4. Destroi ORB
		orb->destroy();
	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}

bhldr__dataFormat valueToStruct (Value value) {
	bhldr__dataFormat data;
	data.infoName = value.id.in();
	data.value = std::to_string(value.storedValue);
	data.timestamp = value.timestamp.in();
	data.dataType = static_cast<bhldr__DataType>(value.type);
    return data;
}

int bhldr__lookup(struct soap *soap, std::vector<struct bhldr__requestFormat> input, std::vector<bhldr__dataFormat> &data) {
	std::vector<struct bhldr__requestFormat>::iterator itRequests = input.begin();
	std::vector<Value> resultingValues;
	while (itRequests != input.end()) {
		// Convert dataFormat to Value
		std::string timestamp;
		Value value;
		value.id = itRequests->infoName.c_str();
		value.timestamp = itRequests->timestamp.c_str();
		Beholder->getValue(value);
		// value
		resultingValues.push_back(value);
		++itRequests;
		data.push_back(valueToStruct(value));
	}
  	return SOAP_OK;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, std::vector<bhldr__dataFormat> messageList, bool &result) {
	::DSMComms::ValueSequence valueList;

	for (bhldr__dataFormat message : messageList) {
		// Checking the validity of the data
		if (message.infoName.empty() || message.value.empty() || message.timestamp.empty()) {
			continue;
		}

		Value value;
		// Convert dataFormat to Value
		value.id = message.infoName.c_str();
		value.storedValue = std::stod(message.value);
		value.timestamp = message.timestamp.c_str();
		value.type = (DataType)message.dataType;
		Beholder->storeValue(value);
	}
	result = true;
	return SOAP_OK;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, std::vector<bhldr__dataFormat> messageList) {
	// std::cout << "CALLED" << std::endl;
	for (bhldr__dataFormat message : messageList) {
		std::cout <<  "updateInfo called" << std::endl
					<< "infoName: " << message.infoName << std::endl
					<< "value: " << message.value << std::endl
					<< "timestamp: " << message.timestamp << std::endl;
	}
	return SOAP_OK;
}
