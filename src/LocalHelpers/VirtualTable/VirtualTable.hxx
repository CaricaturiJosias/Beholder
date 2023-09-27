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
#include <set>
#include <memory>

namespace LocalMachine {

    // Should come after avros and openssl3

    typedef std::string keyName;
    typedef void * dataPointer;
    typedef std::shared_ptr<dataPointer> EncryptedValue;

    typedef struct {
        EncryptedValue data;
        int dataType; // Most likely digital and analog from default type
    } fileDataValue;

    typedef std::set<std::pair<keyName, EncryptedValue>> valueMap;

    class VirtualTable {

        public:

            VirtualTable * GetInstance();

            VirtualTable();
            ~VirtualTable();

            valueMap GetValueMap();

            EncryptedValue GetStoredValue(keyName id);

            bool StoreValue(dataPointer value, keyName valueName);

        private:
            
            static double numRows;

            static valueMap dataMapValue;

            static VirtualTable * table;
    };

} // Namespace LocalMachine