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
			if (a == 1) {
				int b = Information::ANALOG;
				// LocalMachine::SchemaUtils::GetSchema(Information::ANALOG);
				cout << "Memory: " << LocalMachine::Machine::GetMemory() << endl;
				// std::string test = LocalMachine::Machine::GetGlobalFile();
				std::string test = LocalMachine::SchemaUtils::GetSchema(Information::ANALOG);
				// cout << "Schema: " << test;
				command = "fim";
				// cout << "Global file " << test << endl;
			}
		} while (command != "fim");

		// 4. Destroi ORB
		orb->destroy();
	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}
