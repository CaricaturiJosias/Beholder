#include "BeholderI.h"
#include <iostream>

// DSMComms includes
#include <Beholder/SchemaUtils.hxx>
#include <Beholder/MachineUtils.hxx>

// #include <DSMComms/Information.hxx>

using namespace std;

extern CORBA::ORB_var orb;

Beholder_i::Beholder_i (const std::string& account_id) {
  // nothing happens
}


void Beholder_i::LogEventAll(std::string valor, ::DSMComms::EventEnum event) {
  // nothing happens
}

void Beholder_i::getValue(::DSMComms::StringSeq valueId, ::DSMComms::ValSeq toGetValue, ::DSMComms::DataType type) {
  for (std::string id : valueId) {
    std::cout << "Received lookup for id " << id << std::endl;

    LocalMachine::MachineUtils;
  }
}

void Beholder_i::storeValue(::DSMComms::StringSeq valueId, const ::DSMComms::ValSeq & toSetValue, ::DSMComms::DataType type) {
  // We expect the data to have already been checked out
  LocalMachine::SchemaUtils schemaItem;
  std::string value = std::to_string(toSetValue.storedValue);
  std::string timestamp = std::to_string(toSetValue.timestamp);

  int32_t typeVal = type;
  Information::Information * info = new Information::Information(valueId, value, timestamp, std::string("1"), typeVal);
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
