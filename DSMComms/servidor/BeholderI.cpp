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

void Beholder_i::getValue(::DSMComms::Value & toGetValue) {
  std::string timestamp;
  if (toGetValue.timestamp.in() != nullptr) {
    timestamp = toGetValue.timestamp.in();
  }
  std::string id = toGetValue.id.in();
  std::vector<Information::Information> result = LocalMachine::MachineUtils::LookUpData(id, timestamp);


  if (result.size() == 0) {
    toGetValue.storedValue = 0;
    toGetValue.type = DSMComms::DataType::UNKNOWN;
    return;
  }

  Information::Information firstInfo = *(result.begin());
  toGetValue.id = firstInfo.GetInfoId().c_str();
  toGetValue.storedValue = std::stod(firstInfo.GetInfoValue());
  toGetValue.timestamp = firstInfo.GetInfoTimeStamp().c_str();
  toGetValue.type = static_cast<DSMComms::DataType>(std::stoi(firstInfo.GetInfoQuality()));

  for (Information::Information info : result) {
    DSMComms::Value value;
    value.id = info.GetInfoId().c_str();
    value.storedValue = std::stod(info.GetInfoValue());
    value.timestamp = info.GetInfoTimeStamp().c_str();
    value.type = static_cast<DSMComms::DataType>(std::stoi(info.GetInfoQuality()));
  }
  return;
}

void Beholder_i::storeValue(const ::DSMComms::Value & toSetValue) {
  std::cout << "Received store request " << std::endl;
  // We expect the data to have already been checked out
  LocalMachine::SchemaUtils schemaItem;

  std::string id = toSetValue.id.in();
  std::string strValue = std::to_string(toSetValue.storedValue);
  std::string timestamp = toSetValue.timestamp.in();

  int32_t typeVal = toSetValue.type;
  Information::Information * info = new Information::Information(id, strValue, timestamp, std::string("1"), typeVal);
  schemaItem.SaveData(*info);

}

void Beholder_i::shutdown (const string password)
{
	if (password == "SD") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}
