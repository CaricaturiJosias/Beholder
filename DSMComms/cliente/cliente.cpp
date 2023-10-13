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


int bhldr__lookup(struct soap *soap, std::string infoId, bhldr__dataFormat &data) {
	std::cout <<  "Lookup called" << std::endl
				<< "InfoId: " << infoId << std::endl;
	// Convert dataFormat to Value
	Value value;
	value.storedValue = std::stod(data.value);
	value.timestamp = std::stol(data.timestamp);
	
	// Enum to int to other enum
	DataType type = (DataType)data.dataType;

	Beholder->getValue(infoId.c_str(), value, type);
  	return 200;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, bhldr__dataFormat message, bool &result) {
	std::cout << "CALLED" << std::endl;
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
	return 200;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, bhldr__dataFormat message) {
	std::cout << "CALLED" << std::endl;
	std::cout <<  "updateInfo called" << std::endl
				<< "infoName: " << message.infoName << std::endl
				<< "value: " << message.value << std::endl
				<< "timestamp: " << message.timestamp << std::endl;
	return 200;
}

