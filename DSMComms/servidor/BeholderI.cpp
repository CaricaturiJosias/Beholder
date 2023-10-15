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

void Beholder_i::getValue(const std::string valueId, ::DSMComms::ValueSequence & toGetValue) {
  std::cout << "Received lookup for id " << valueId << std::endl;
  std::vector<Information::Information> result = LocalMachine::MachineUtils::LookUpData(valueId);
  std::cout << "Size of result: " << result.size() << std::endl;

  for (Information::Information info : result) {
    // std::cout << "Printing info: " << std::endl << info.toString() << std::endl;
    DSMComms::Value value;
    value.id = info.GetInfoId().c_str();
    value.storedValue = std::stod(info.GetInfoValue());
    value.timestamp = std::stol(info.GetInfoTimeStamp());
    value.type = static_cast<DSMComms::DataType>(std::stoi(info.GetInfoQuality()));
    toGetValue.push_back(value);
  }
  return;
}

void Beholder_i::storeValue(const ::DSMComms::idSequence & valueId, const ::DSMComms::ValueSequence & toSetValues) {
  // We expect the data to have already been checked out
  LocalMachine::SchemaUtils schemaItem;
  std::vector<char *>::const_iterator  charIt = valueId.begin();
  std::vector<DSMComms::Value>::const_iterator  valueIt = toSetValues.begin();

  while (valueIt != toSetValues.end()) {
    DSMComms::Value value = *valueIt;
    std::string strValue = std::to_string(value.storedValue);
    std::string timestamp = std::to_string(value.timestamp);
    std::string id = std::string(*charIt);

    int32_t typeVal = value.type;
    Information::Information * info = new Information::Information(id, strValue, timestamp, std::string("1"), typeVal);
    schemaItem.CompressData(info);

    ++valueIt;
    ++charIt;
  }

}

void Beholder_i::shutdown (const string password)
{
	if (password == "SD") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}
