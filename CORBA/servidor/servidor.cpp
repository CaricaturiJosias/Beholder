//
// SERVIDOR BEHOLDER
//

#include <iostream>
#include <fstream>
#include <string>
#include "./BeholderI.h"

using namespace std;

CORBA::ORB_var orb = CORBA::ORB::_nil();

int main(int argc, char* argv[])
{
    // Verifica parametros da linha de comando
    if (argc < 2) {
		cerr << "USO: " << argv[0] << " <arq_ior>" << endl;
		return 1;
    }

    try {

		// 1. Inicia ORB
		cout << "Inciando ORB" << endl;
		orb = CORBA::ORB_init(argc,argv,"ORB");

		// 2. Ativa RootPOA
	    cout <<  "Ativando RootPOA" << endl;
		PortableServer::POA_var root_poa;
		CORBA::Object_ptr tmp_ref;
		tmp_ref = orb->resolve_initial_references("RootPOA");
		root_poa = PortableServer::POA::_narrow(tmp_ref); // safe casting
		PortableServer::POAManager_var poa_manager = root_poa->the_POAManager();
		poa_manager->activate();

		// 3. Instancia "servants"
		cout << "Instanciando servant" << endl;
		Beholder_i beh_i(argv[1]); // beholder name = ior file name

		// 4. Registra servos no POA, criando objetos distribuídos
		cout << "Registrando servos no POA (criando objetos CORBA)" << endl;
		DSMComms::POA_Beholder_var beholder = beh_i._this(); // returns reference to the object

		// 5. Publica IOR
		cout <<  "Publicando IOR (arquivo \"" << argv[1] << "\")" << endl;
		CORBA::String_var ior = orb->object_to_string(beholder.in());
		ofstream arq_ior(argv[1]);
		arq_ior << ior << endl;
		arq_ior.close();

		// 6. Aguarda requisições
		cout << "Aguardando requisicoes...\n" << endl;
		orb->run();

		// 7. Finaliza
		root_poa->destroy(true,true);
		orb->destroy();

    } catch (CORBA::Exception& e) {
		cerr << "CORBA exception: " << e << endl;
    }

    return 0;
}
