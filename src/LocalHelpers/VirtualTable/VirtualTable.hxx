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
#include <cstdint>
#include <string>
#include <memory>
#include <set>
#include <map>

namespace LocalMachine {

    // Should come after avros and openssl3

    typedef std::string keyName;
    typedef std::string dataFilePath;
    typedef std::string EncryptionKey;

    struct fileDataValue{
        dataFilePath data;
        EncryptionKey key;
        int32_t dataType; // Most likely digital and analog from default type
        
        // Temporary, for place holder functions
        fileDataValue () {
            data = "";
            key = "";
            dataType = 0;
        }

        fileDataValue (dataFilePath dataInput, EncryptionKey keyInput, int32_t dataTypeInput) {
            data = dataInput;
            key = keyInput;
            dataType = dataTypeInput;
        }

        fileDataValue (dataFilePath dataInput, int32_t dataTypeInput) {
            data = dataInput;
            key = ""; // No encryption key = not encrypted
            dataType = dataTypeInput;
        }
    };

    typedef std::map<keyName, fileDataValue> valueMap;

    class VirtualTable {

        public:

            VirtualTable * GetInstance();

            VirtualTable();
            ~VirtualTable();

            valueMap GetValueMap();

            fileDataValue GetStoredValue(keyName id);

            bool StoreValue(dataFilePath value, keyName valueName, int32_t dataType);

            bool StoreValue(dataFilePath value, keyName valueName, EncryptionKey encryptionKey, int32_t dataType);

        private:
            
            static double numRows;

            static valueMap dataMapValue;

            static VirtualTable * table;
    };

} // Namespace LocalMachine