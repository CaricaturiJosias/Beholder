/**
 * @file VirtualTable.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Contains the class declaration to treating the data table in a Beholder instance
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

// TODO - Use Avro here for data storing, temporary types here
typedef std::string storedValue;
typedef int storageId;
typedef std::string keyName;
typedef void * AvroValue;

typedef std::map<storageId, keyName> keyMap;
typedef std::map<storageId, AvroValue> valueMap;

class VirtualTable {

    public:
        VirtualTable * GetInstance();

        VirtualTable();
        ~VirtualTable();

        keyMap GetKeyMap();
        valueMap GetValueMap();

        void * GetStoredValue(storageId id);

    private:
        
        static double numRows;

        static keyMap dataMapKey;
        static valueMap dataMapValue;

        static VirtualTable * table;
};

} // Namespace LocalMachine