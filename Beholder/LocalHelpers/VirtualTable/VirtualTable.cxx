/**
 * @file VirtualTable.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Contains methods regarding the virtual table of a machine and its stored data
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "VirtualTable.hxx"
#include <MachineUtils.hxx>
#include <SchemaUtils.hxx>
#include <filesystem>

namespace LocalMachine {
    
    uint32_t MAX_BUFFER_SIZE = 1;

    double VirtualTable::numRows = 0;

    valueMap VirtualTable::dataMapValue = valueMap{};

    std::shared_ptr<VirtualTable> VirtualTable::table = nullptr;

    BUFFER_MAP VirtualTable::s_infoBuffer = {
        {ANALOG, {}},
        {DIGITAL, {}}
    };

    std::shared_ptr<VirtualTable> VirtualTable::GetInstance() {
        if (table == nullptr) {
            table.reset(new VirtualTable());
        }
        return table;
    }

    VirtualTable::VirtualTable() {
        // Nothing
    }

    VirtualTable::~VirtualTable() {
        // Nothing
    }

    valueMap VirtualTable::GetValueMap() {
        return dataMapValue;
    }

    std::vector<Information::Information> VirtualTable::GetStoredValue(keyName id) {
        std::vector<Information::Information> result;
        std::vector<Information::Information> instanceVector;
        
        valueMap::iterator it = dataMapValue.begin();
        std::vector<fileDataValue> instances;
        if (it == dataMapValue.end()) {
            // TODO - LOG ERROR
            return result;
        }

        // For every instance, look at the encrypted file and search for any ID that matches
        for (fileDataValue dataInstance : instances) {
            // data is a filepath
        }


        for (fileDataValue dataInstance : instances) {
            instanceVector = SchemaUtils::GetData(dataInstance, id);
            if (instanceVector.empty()) {
                continue;
            }
            result.insert(result.end(), instanceVector.begin(), instanceVector.end());
        }
        return result;
    }

    bool VirtualTable::StoreValue(dataFilePath data, keyName valueName, int32_t dataType) {
        // No encryption key = not encrypted
        if (valueName.empty()) {
            // TODO - LOG error
            return false;
        }

        valueMap::iterator it = dataMapValue.find(valueName);
        if (it != dataMapValue.end()) {
            // TODO - Log existing value
            return false;
        }
        fileDataValue fileInstance = fileDataValue(data, dataType);
        dataMapValue[valueName].push_back(fileInstance);
        return true;
    }

    bool VirtualTable::StoreValue(  dataFilePath value,
                                    keyName valueName,
                                    EncryptionKey encryptionKey,
                                    int32_t dataType) {
        if (encryptionKey.empty()) {
            // TODO - LOG error
            return false;
        } else if (valueName.empty()) {
            // TODO - Log empty value
            return false;
        }

        valueMap::iterator it = dataMapValue.find(valueName);
        if (it != dataMapValue.end()) {
            // TODO - Log existing value
            return false;
        }

        fileDataValue fileInstance = fileDataValue(value, dataType);
        dataMapValue[valueName].push_back(fileInstance);
        return true;
    }

} // Namespace LocalMachine