// hello.cpp
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/ns.nsmap" // include XML namespaces
#include "threads.h" /* use gsoap/plugin/threads.h portable threads */
#include<unistd.h>               // for linux 
#include <iostream>

int main()
{
  return soap_serve(soap_new1(SOAP_IO_KEEPALIVE));
}
int ns__hello(struct soap *soap, std::string name, std::string& greeting)
{
  greeting = "Hello " + name;
  std::cout << "Hi" << std::endl;
  sleep( 1000 );    // time_period in seconds
  return SOAP_OK;
}