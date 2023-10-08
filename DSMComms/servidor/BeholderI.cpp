#include "BeholderI.h"
#include <iostream>

using namespace std;

extern CORBA::ORB_var orb;

Beholder_i::Beholder_i (const std::string& account_id) {
  // nothing happens
}


void Beholder_i::LogEventAll(const std::string valor, DSMComms::EventEnum event) {
  // nothing happens
}
void Beholder_i::getValue(const std::string valueId, DSMComms::Value_out toGetValue) {
  // nothing happens
}

void Beholder_i::shutdown (const string password)
{
	if (password == "SD") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}
