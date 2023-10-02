//
// CLIENTE DE Beholder BANCÁRIA SIMPLES
//
// Arquitetura de Sistemas Distribuídos, Paralelos e Concorrentes
// Escola Politécnica -- PUCPR
// Prof. Luiz Lima Jr. (laplima@ppgia.pucpr.br)
//

#include <iostream>
#include <string>
#include <beholder/SchemaUtils.hxx>
#include <beholder/Information.hxx>
#include <beholder/Machine.hxx>
#include "BeholderC.h"

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
				Information::Information * info = new Information::Information(
					std::to_string(n),
					"1.1",
					"2023-10-01 11:31:42",
					"2",
					Information::ANALOG
				);
				LocalMachine::SchemaUtils::CompressData(info);
			}
			command = "fim";
		} while (command != "fim");

		// 4. Destroi ORB
		orb->destroy();
	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}
