// calculator.cpp
// This file implements the web service functions.

#include "calculator.h"

int ns__add(int a, int b, int &result) {
    result = a + b;
    return SOAP_OK;
}