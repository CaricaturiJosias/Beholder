//
// CLIENTE DE CONTA BANCÁRIA SIMPLES
//
// Arquitetura de Sistemas Distribuídos, Paralelos e Concorrentes
// Escola Politécnica -- PUCPR
// Prof. Luiz Lima Jr. (laplima@ppgia.pucpr.br)
//

#include <iostream>
#include <string>
#include "ContaC.h"

using namespace std;

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
		Conta_var account;

		tmp_ref = orb->string_to_object(argv[1]);
		account = Conta::_narrow(tmp_ref);

		// 3. Use account

		string command;
		string password;
		CORBA::Float amount;
		string dest_ior;

		cout << "Commandos:\n\tsaldo\n\tid\n\tdeposito\n"
		<< "\tsaque\n\ttransfere\n\tshutdown\n\tfim" << endl;

		do {
			cout << "> ";
			cin >> command;
			if (command == "saldo") {
				cout << "\tSaldo = " << account->saldo() << endl;
			} else if (command == "id") {
				cout << "\tId = " << account->id() << endl;
			} else if (command == "deposito") {
				cin >> amount;
				account->deposito(amount);
				cout << "\tOK" << endl;
			} else if (command == "saque") {
				cin >> amount;
				try {
					account->saque(amount);
					cout << "\tOK" << endl;
				} catch (SaldoInsuficiente&) {
					cout << "\t[SaldoInsuficiente]" << endl;
				}
			} else if (command == "transfere") {
				cin >> amount;
				cin >> dest_ior;
				try {
					tmp_ref = orb->string_to_object(dest_ior.c_str());
					Conta_var dest = Conta::_narrow(tmp_ref);
					account->transfere(amount,dest);
					cout << "\tOK" << endl;
				} catch (SaldoInsuficiente&) {
					cout << "\t[SaldoInsuficiente]" << endl;
				}
			} else if (command == "shutdown") {
				cin >> password;
				account->shutdown(password);
				command = "fim";	// exits client too
			}

		} while (command != "fim");

		// 4. Destroi ORB
		orb->destroy();
	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}
