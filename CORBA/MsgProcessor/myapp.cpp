#include "Generated/soapH.h"
#include "Generated/bhldr.nsmap" // include XML namespaces
struct soap *soap = soap_new(); // new context
int main () {
    std::string greeting;
    soap_stream_fault(soap, std::cerr);
    soap_destroy(soap); // delete managed deserialized C++ instances
    soap_end(soap);     // delete other managed data
    soap_free(soap);    // free context
}