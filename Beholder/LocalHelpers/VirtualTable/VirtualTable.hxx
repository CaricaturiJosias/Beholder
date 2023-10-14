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

#include <Information.hxx>
#include "time.h"
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <map>

namespace LocalMachine {

    struct informationValue {
        std::string id;
        std::string value;
        std::string quality;
        std::string timestamp;

        informationValue (Information::Information info) {
            id = info.GetInfoId();
            id.shrink_to_fit();
            value = info.GetInfoValue();
            value.shrink_to_fit();
            quality = info.GetInfoQuality();
            quality.shrink_to_fit();
            timestamp = info.GetInfoTimeStamp();
            timestamp.shrink_to_fit();
        }
    };

    // Should come after avros and openssl3
    typedef std::string keyName;
    typedef std::string dataFilePath;
    typedef std::string EncryptionKey;

    typedef std::vector<LocalMachine::informationValue> INFO_LIST;
    typedef std::map<int32_t, INFO_LIST> BUFFER_MAP;

    extern uint32_t MAX_BUFFER_SIZE;

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

        bool empty() {
            if (data.empty() &&
                key.empty() &&
                dataType == 0) {
                return true;
            }
            return false;
        }
    };

    typedef std::map<keyName, fileDataValue > valueMap;

    class VirtualTable {

        public:

            static std::shared_ptr<VirtualTable> GetInstance();

            VirtualTable();
            ~VirtualTable();

            void ColdStartPopulate();

            valueMap GetValueMap();

            std::vector<Information::Information> GetStoredValue(keyName id);

            bool StoreValue(dataFilePath value, keyName valueName, int32_t dataType);

            bool StoreValue(dataFilePath value, keyName valueName, EncryptionKey encryptionKey, int32_t dataType);

            BUFFER_MAP * getBuffer() { return &s_infoBuffer; }

        private:
            
            static double numRows;

            static valueMap dataMapValue;

            static std::shared_ptr<VirtualTable> table;

            static BUFFER_MAP s_infoBuffer;
    };

} // Namespace LocalMachine