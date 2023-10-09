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

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "USAGE: " << argv[0] << " file://<ior_file>" << endl;
		return 1;
	}

	try {
		// 1. Initiate ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc,argv,"ORB");

		// 2. Obtain object reference
		CORBA::Object_ptr tmp_ref;
		POA_Beholder_var Beholder;

		tmp_ref = orb->string_to_object(argv[1]);
		Beholder = POA_Beholder::_narrow(tmp_ref);

		// 3. Use Beholder

		string command = "a";
		string password;
		CORBA::Float amount;
		string dest_ior;

		cout << "Teste:\n\ta" << endl;
		int a = 1;
		do {
			for (int n = 1; n < 20; n++)  {
				const char * valueId = std::to_string(n).c_str();
				DSMComms::Value valueInstance;
				valueInstance.storedValue = n;
				valueInstance.timestamp = 123234234;
			}
			command = "fim";
		} while (command != "fim");
		struct soap *soap = soap_new();
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
  return 200;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, bhldr__dataFormat message, bool &result) {
  std::cout <<  "registerInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;
//   Information::Information infoInstance(
//     message.infoName,
//     message.value,
//     message.timestamp,
//     "1",
//     Information::ANALOG);
//   Entity::Entity sender("No id haha", "no address", Entity::DATA_SOURCE);
//   LocalMachine::SchemaUtils schemaInstance;
//   if (schemaInstance.SaveData(infoInstance)) {
//     return 200;
//   }
  return 418;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, bhldr__dataFormat message) {
  std::cout <<  "updateInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;
  return 200;
}

