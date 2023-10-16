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
#include <Machine.hxx>
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
        ColdStartPopulate();
    }

    VirtualTable::~VirtualTable() {
        // Nothing
    }

    void VirtualTable::ColdStartPopulate() {
        // Lets fill the info buffer
        std::filesystem::path storagePath = LocalMachine::Machine::GetStoragePath();
        // std::cout   << "VirtualTable::ColdStartPopulate called"
                    // << " with file " << storagePath << std::endl;
        dataMapValue = SchemaUtils::GetDataInfoFromFiles(storagePath);
    }

    valueMap VirtualTable::GetValueMap() {
        return dataMapValue;
    }

    std::vector<Information::Information> VirtualTable::GetStoredValue(keyName id, std::string timestamp) {
        std::vector<Information::Information> result;
        std::vector<Information::Information> instanceVector;
        
        // std::cout << "VirtualTable::GetStoredValue looking for " << id << std::endl;

        valueMap::iterator it = dataMapValue.begin();
        std::vector<fileDataValue> instances;
        if (it == dataMapValue.end()) {
            // TODO - LOG ERROR
            std::cout << "VirtualTable::GetStoredValue empty " << std::endl;
            // return result;
        }

        std::cout << "VirtualTable::GetStoredValue not empty " << std::endl;
        // For every instance, look at the encrypted file and search for any ID that matches
        while (it != dataMapValue.end()) {
            fileDataValue dataInstance = it->second;
            instanceVector = SchemaUtils::GetData(dataInstance, id);
            if (instanceVector.empty()) {
                std::cout << "Empty instance" << std::endl;
                ++it;
                continue;
            }

            if (timestamp.empty() || timestamp == Information::DEFAULT_TIME) {
                result.insert(result.end(), instanceVector.begin(), instanceVector.end());
                std::cout << "Timestamp is default or empty, timestamp: " << timestamp << std::endl;
            } else {
                std::cout << "Timestamp not empty: " << timestamp << std::endl;
                for (Information::Information instance : instanceVector) {
                    // If timestamp is defined, look for a match
                    std::cout << "Instance: " << instance.GetInfoTimeStamp() << std::endl;
                    if (instance.GetInfoTimeStamp() == timestamp) {
                        std::cout << "Found " << instance.GetInfoTimeStamp() << std::endl;
                        result.push_back(instance);
                    }
                }
            }
            ++it;
        }
        return result;
    }

    bool VirtualTable::StoreValue(dataFilePath data, keyName valueName, int32_t dataType) {
        std::string idPrefix = ((dataType == ANALOG) ? std::string("A") : ""+ std::string("D"));
        std::string valueId = idPrefix + valueName;
        // No encryption key = not encrypted
        if (valueName.empty()) {
            // TODO - LOG error
            return false;
        }

        valueMap::iterator it = dataMapValue.find(valueId);
        if (it != dataMapValue.end()) {
            // TODO - Log existing value
            std::cout <<  "Stored value already exists: " << it->first << std::endl;
            return false;
        }
        fileDataValue fileInstance = fileDataValue(data, dataType);
        std::cout <<  "New value for the data map: " << valueId << std::endl;
        dataMapValue[valueId] = fileInstance;
        return true;
    }

    bool VirtualTable::StoreValue(  dataFilePath value,
                                    keyName valueName,
                                    EncryptionKey encryptionKey,
                                    int32_t dataType) {
        std::string idPrefix = ((dataType == ANALOG) ? std::string("A") : ""+ std::string("D"));
        std::string valueId = idPrefix + valueName;
        if (encryptionKey.empty()) {
            // TODO - LOG error
            return false;
        } else if (valueName.empty()) {
            // TODO - Log empty value
            return false;
        }

        valueMap::iterator it = dataMapValue.find(valueId);
        if (it != dataMapValue.end()) {
            // TODO - Log existing value
            std::cout <<  "Stored value already exists: " << it->second.data << std::endl;
            return false;
        }

        fileDataValue fileInstance = fileDataValue(value, dataType);
        std::cout <<  "New value for the data map: " << valueId << std::endl;
        dataMapValue[valueId] = fileInstance;
        return true;
    }

} // Namespace LocalMachine