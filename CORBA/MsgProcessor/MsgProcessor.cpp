// hello.cpp
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/bhldr.nsmap" // include XML namespaces
#include <iostream>

int main() {
  struct soap *soap = soap_new();

  soap->accept_timeout = 3600; // server stops after 1 hour of inactivity 
  soap->send_timeout =  soap->recv_timeout = 5;     // 5 seconds max socket delay 
  soap->transfer_timeout = 10;                 /* max time for send or receive of messages (sec) */
  
  SOAP_SOCKET m;
  m = soap_bind(soap, NULL, 8081, 10);  // small BACKLOG for iterative servers 
  std::cout << "State: " << soap->state << std::endl;
  while (soap_valid_socket(soap_accept(soap)))
  {
    soap_serve(soap);   /* serve request, ignoring failures */
    soap_destroy(soap); /* delete deserialized objects */
    soap_end(soap);     /* delete heap and temp data */
  }
  soap_destroy(soap); /* delete deserialized objects */
  soap_end(soap);     /* delete heap and temp data */
  soap_free(soap);    /* we're done with the context */
}

int bhldr__lookup(struct soap *soap, std::string infoId, bhldr__dataFormat &data) {
  std::cout <<  "Lookup called" << std::endl
            << "InfoId: " << infoId << std::endl;
  return true;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, bhldr__dataFormat message, bool &result) {
  std::cout <<  "registerInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;

  result = true;
  return 1;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, bhldr__dataFormat message) {
  std::cout <<  "updateInfo called" << std::endl
            << "infoName: " << message.infoName << std::endl
            << "value: " << message.value << std::endl
            << "timestamp: " << message.timestamp << std::endl;
  return 1;
}