/**
 * @file MachineUtils.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Contains methods regarding the virtual table of a machine and its stored data
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

class VirtualTable {

    public:
        VirtualTable * GetInstance();

        VirtualTable();
        ~VirtualTable();

        keyMap GetKeyMap();
        valueMap GetValueMap();

        Value * GetStoredValue(storageId id);

    private:
        
        static double numRows;

        static keyMap dataMapKey;
        static valueMap dataMapValue;

        static VirtualTable * table;
};

} // Namespace LocalMachine