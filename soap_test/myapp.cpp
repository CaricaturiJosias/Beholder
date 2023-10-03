#include "generated/soapH.h"
#include "generated/Service.nsmap" // include XML namespaces
#include "generated/soapStub.h"
struct soap *soap = soap_new(); // new context
std::string greeting;
int main() {
    _ns2__hello hello;
    hello.name = "world";
    _ns2__helloResponse helloResponse;
    if (soap_call___ns1__hello(soap, "http://127.0.0.1", NULL, &hello, &helloResponse) == SOAP_OK)
    std::cout << greeting << std::endl;
    else
    soap_stream_fault(soap, std::cerr);
    soap_destroy(soap); // delete managed deserialized C++ instances
    soap_end(soap);     // delete other managed data
    soap_free(soap);    // free context
}
