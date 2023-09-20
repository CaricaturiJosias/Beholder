/**
 * @file AvrosHelper.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Contains the class definitions to the Avros library helpers
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "time.h"
#include <string>
#include <map>

namespace LocalMachine {

// TODO - Use avros here for data storing, temporary types here
typedef std::string storedValue;
typedef int storageId;

typedef struct ValueStruct {
    double val; // Actual Value
    clock_t timestamp; // timestamp of the value
} Value;

typedef std::map<storageId, std::string> keyMap;
typedef std::map<storageId, ValueStruct> valueMap;

class AvroHelper {

    public:

        AvroHelper();
        ~AvroHelper();


};

} // Namespace LocalMachine