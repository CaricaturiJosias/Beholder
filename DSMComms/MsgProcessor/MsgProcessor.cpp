// hello.cpp
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/bhldr.nsmap" // include XML namespaces
#include <iostream>

#include <SchemaUtils.hxx>
#include <Information.hxx>
#include <BaseMsg.hxx>
#include <Entity.hxx>

int Get_response(struct soap * soap);

int main() {
  struct soap *soap = soap_new();
  soap_serve(soap);   /* serve request, ignoring failures */
  soap_destroy(soap); /* delete deserialized objects */
  soap_end(soap);     /* delete heap and temp data */
  soap_free(soap);    /* we're done with the context */
  return 0;
}

int bhldr__lookup(struct soap *soap, std::string infoId, bhldr__dataFormat &data) {
  std::cout <<  "Lookup called" << std::endl
            << "InfoId: " << infoId << std::endl;
  return 200;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, bhldr__dataFormat message, bool &result) {
  std::cout <<  "registerInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;
  Information::Information infoInstance(
    message.infoName,
    message.value,
    message.timestamp,
    "1",
    Information::ANALOG);
  Entity::Entity sender("No id haha", "no address", Entity::DATA_SOURCE);
  Message::BaseMsg msg();
  result = true;
  return 200;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, bhldr__dataFormat message) {
  std::cout <<  "updateInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;
  return 200;
}
