#include "BeholderI.h"
#include <iostream>

// DSMComms includes
#include <Beholder/SchemaUtils.hxx>
#include <Beholder/MachineUtils.hxx>
#include <Beholder/Information.hxx>

// #include <DSMComms/Information.hxx>

using namespace std;

extern CORBA::ORB_var orb;

Beholder_i::Beholder_i (const std::string& account_id) {
  // nothing happens
}


void Beholder_i::LogEventAll(std::string valor, ::DSMComms::EventEnum event) {
  // nothing happens
}

void Beholder_i::getValue(const std::string valueId, ::DSMComms::Value_out toGetValue) {
  std::cout << "Received lookup for id " << valueId << std::endl;
  std::vector<Information::Information> result = LocalMachine::MachineUtils::LookUpData(valueId);
  std::cout << "Size of result: " << result.size() << std::endl;

  for (Information::Information info : result) {
    // std::cout << "Printing info: " << std::endl << info.toString() << std::endl;
  }
}

void Beholder_i::storeValue(const std::string valueId, const ::DSMComms::Value & toSetValue, ::DSMComms::DataType type) {
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
