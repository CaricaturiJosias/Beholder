// server.cpp
// This file contains the main program to run the web service.

#include "calculator.h"
#include "stdsoap2.h"

int main() {
    struct soap soap;
    soap_init(&soap);

    if (soap_bind(&soap, NULL, 12345, 100) < 0) {
        soap_print_fault(&soap, stderr);
        exit(1);
    }

    printf("Web service is running on port %d...\n", soap.port);

    while (1) {
        soap_accept(&soap);
        soap_serve(&soap);
        soap_end(&soap);
    }

    soap_done(&soap);
    return 0;
}