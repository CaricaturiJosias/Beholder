// hello.cpp
#include "Generated/soapH.h"  // include the generated source code headers
#include "Generated/bhldr.nsmap" // include XML namespaces
int main()
{
  return soap_serve(soap_new());
}
int bhldr__lookup(struct soap *soap, std::string infoId, bhldr__dataFormat &data) {
  return 1;
}

//gsoap MsgProcessor service method: registerInfo register an info
int bhldr__registerInfo(struct soap *soap, bhldr__dataFormat message, bool &result) {
  return 1;
}

//gsoap MsgProcessor service method: updateInfo update for an info
int bhldr__updateInfo(struct soap *soap, bhldr__dataFormat message) {
  return 1;
}