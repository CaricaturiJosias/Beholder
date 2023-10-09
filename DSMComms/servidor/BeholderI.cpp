#include "BeholderI.h"
#include <iostream>

// DSMComms includes
#include <DSMComms/SchemaUtils.hxx>
// #include <DSMComms/Information.hxx>

using namespace std;

extern CORBA::ORB_var orb;

Beholder_i::Beholder_i (const std::string& account_id) {
  // nothing happens
}


void Beholder_i::LogEventAll(const char * valor, ::DSMComms::EventEnum event) {
  // nothing happens
}

void Beholder_i::getValue(const char * valueId, ::DSMComms::Value_out toGetValue, ::DSMComms::DataType type) {
  // nothing happens
}

void Beholder_i::storeValue(const char * valueId, const ::DSMComms::Value & toSetValue, ::DSMComms::DataType type) {
  LocalMachine::SchemaUtils schemaItem;
  std::string id(valueId);
  std::string value = std::to_string(toSetValue.storedValue);
  std::string timestamp = std::to_string(toSetValue.timestamp);

  int32_t typeVal = type;
  Information::Information * info = new Information::Information(id, value, timestamp, std::string("1"), typeVal);
  schemaItem.CompressData(info);
}

void Beholder_i::shutdown (const string password)
{
	if (password == "SD") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}
