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

// Beholder
// #include <Beholder/VirtualTable.hxx>
// #include <Beholder/SchemaUtils.hxx>

using namespace std;
using namespace DSMComms;

// So we can contact the server on the SOAP requests
POA_Beholder_var Beholder;

int port = 8080; //  Port number we are using

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
		// struct soap *soap = soap_new1(SOAP_IO_KEEPALIVE); 
		// soap->send_timeout = soap->recv_timeout = 5; /* 5 sec socket idle timeout */
  		// soap->transfer_timeout = 30;                         /* 30 sec message transfer timeout */
  		// SOAP_SOCKET m = soap_bind(soap, NULL, port, 100);              /* master socket */
		// if (soap_valid_socket(m))
		// {
		// 	while (soap_valid_socket(soap_accept(soap)))
		// 	{
		// 	THREAD_TYPE tid;
		// 	void *arg = (void*)soap_copy(soap);
		// 	/* use updated THREAD_CREATE from plugin/threads.h https://www.genivia.com/files/threads.zip */
		// 	if (arg)
		// 		while (THREAD_CREATE(&tid, (void*(*)(void*))process_request, arg))
		// 		sleep(1);
		// 	}
		// }
		struct soap * soap = soap_new();
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

// void buildResponse(struct soap *soap) {
// 	soap->http_content = "text/xml; charset=utf-8"; // HTTP header with text/xml content 
// 	if (soap_response(soap, SOAP_FILE)) {
// 		soap_envelope_begin_out(soap);
// 		soap_envelope_begin_out(soap);
//    		soap_putheader(soap);
//    		soap_body_begin_out(soap);
//    		// soap_put_bhldr__lookupResponse(soap, &data, "data", "");
//    		soap_body_end_out(soap);
//    		soap_envelope_end_out(soap);
//    		soap_end_send(soap);
// 	}
// }

bhldr__dataFormat valueToStruct (Value value) {
	bhldr__dataFormat data;
	data.infoName = value.id;
	data.value = value.storedValue;
	data.timestamp = value.timestamp;
	data.dataType = static_cast<bhldr__DataType>(value.type);
    return data;
}

int bhldr__lookup(struct soap *soap, std::vector<std::string> infoList, std::vector<std::string> timestamps, std::vector<bhldr__dataFormat> &data) {
	std::cout <<  "Lookup called" << std::endl;
	std::vector<std::string>::iterator itString = infoList.begin();
	std::vector<std::string>::iterator timeIt = timestamps.begin();
	std::cout << "Info list size: " << infoList.size() << std::endl;

	while (itString != infoList.end()) {
		// std::cout <<  "InfoId: " << itString->c_str() << std::endl;
		// Convert dataFormat to Value
		std::string timestamp;
		if (timeIt != timestamps.end()) {
			timestamp = *timeIt;
		}
		Value value;
		value.id = itString->c_str();
		value.timestamp = timestamp.c_str();
		Beholder->getValue(value);
		// value
		std::cout << "Output: " << std::endl
			<< "Id: " << std::string(value.id) << std::endl
			<< "storedValue: " << std::to_string(value.storedValue) << std::endl
			<< "timestamp: " << value.timestamp << std::endl
			<< "type: " << std::to_string(value.type) << std::endl;
		itString++;
	}
  	return 200;
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

		std::cout 	<< "Value: " << std::endl
					<< "id: " << value.id << std::endl
					<< "storedValue: " << value.storedValue << std::endl
					<< "timestamp: " << value.timestamp << std::endl
					<< "type: " << value.type << std::endl;
		Beholder->storeValue(value);
	}

	return 200;
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
	return 200;
}
