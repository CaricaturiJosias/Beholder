//
// cliente da aplicação Beholder
//

#include <iostream>
#include <string>
#include "../idl/BeholderC.h"

// GSOAP
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/bhldr.nsmap" // include XML namespaces

// Beholder
// #include <Beholder/VirtualTable.hxx>
// #include <Beholder/SchemaUtils.hxx>

using namespace std;
using namespace DSMComms;

// So we can contact the server on the SOAP requests
POA_Beholder_var Beholder;

int main(int argc, char* argv[])
{
	// if (argc < 2) {
	// 	cerr << "USAGE: " << argv[0] << " file://<ior_file>" << endl;
	// 	return 1;
	// }

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
		struct soap *soap = soap_new(); 
		soap_serve(soap);                                    // run server
	    soap_destroy(soap);                                  // clean up
	    soap_end(soap);                                      // clean up
	    soap_free(soap);                                     // free context
		// 4. Destroi ORB
		orb->destroy();
	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}


int bhldr__lookup(struct soap *soap, std::vector<std::string> infoList, std::vector<bhldr__dataFormat> &data) {
	std::cout <<  "Lookup called" << std::endl;
	std::vector<std::string>::iterator itString = infoList.begin();
	std::vector<bhldr__dataFormat>::iterator itData = data.begin();

	while (itString != infoList.end() ||
           itData!= data.end()) {
		std::cout <<  "InfoId: " << itString->c_str() << std::endl;
		// Convert dataFormat to Value
		Value value;
		
		// Enum to int to other enum
		DataType type = (DataType)itData->dataType;

		Beholder->getValue(itString->c_str(), value, type);
		itData->value = std::to_string(value.storedValue);
		itData->timestamp = std::to_string(value.timestamp);
		++itString;
		++itData;
	}
  	return 200;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, std::vector<bhldr__dataFormat> messageList, bool &result) {
	std::cout << "CALLED" << std::endl;
	for (bhldr__dataFormat message : messageList) {
		std::cout 	<<  "registerInfo called" << std::endl
					<< "infoName: " << message.infoName << std::endl
					<< "value: " << message.value << std::endl
					<< "timestamp: " << message.timestamp << std::endl;
		// Checking the validity of the data
		if (message.infoName.empty() || message.value.empty() || message.timestamp.empty()) {
			std::cout << "Something is wrong in the input" << std::endl;
			result = false;
			return 418;
		}

		// Convert dataFormat to Value
		Value value;
		value.storedValue = std::stod(message.value);
		value.timestamp = std::stol(message.timestamp);
		
		// Enum to int to other enum
		DataType type = (DataType)message.dataType;

		Beholder->storeValue(message.infoName.c_str(), value, type);
	}
	return 200;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, std::vector<bhldr__dataFormat> messageList) {
	std::cout << "CALLED" << std::endl;
	for (bhldr__dataFormat message : messageList) {
		std::cout <<  "updateInfo called" << std::endl
					<< "infoName: " << message.infoName << std::endl
					<< "value: " << message.value << std::endl
					<< "timestamp: " << message.timestamp << std::endl;
	}
	return 200;
}

