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

#include <cstring>
#include <time.h>

namespace LocalMachine {
    
    uint32_t MAX_BUFFER_SIZE = 30;

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
        Information::Information returningInfo;
        bool mostRecent = timestamp.empty() || timestamp == Information::DEFAULT_TIME;
        std::cout << "VirtualTable::GetStoredValue looking for " << id << std::endl;

        valueMap::iterator it = dataMapValue.begin();
        std::vector<fileDataValue> instances;
        if (it == dataMapValue.end()) {
            // TODO - LOG ERROR
            std::cout << "VirtualTable::GetStoredValue empty " << std::endl;
            return result;
        }

        // For every instance, look at the encrypted file and search for any ID that matches
        while (it != dataMapValue.end()) {
            fileDataValue dataInstance = it->second;
            instanceVector = SchemaUtils::GetData(dataInstance, id);
            if (instanceVector.empty()) {
                ++it;
                continue;
            }
            if (instanceVector.size() == 1) {
                result.push_back(*instanceVector.begin());
                ++it;
                continue;
            }
            if (mostRecent) {
                getTimeDiff(returningInfo, instanceVector);
            } else {
                for (Information::Information instance : instanceVector) {
                    // If timestamp is defined, look for a match
                    if (instance.GetInfoTimeStamp() == timestamp) {
                        result.push_back(instance);
                        return result; // Why look for 2 values with the same timestamp?
                    }
                }
            }
            ++it;
        }

        if (mostRecent) {
            std::cout << "Size of found values: " << instanceVector.size() << std::endl;
            // Latest on all possible files, lets check the latest of them all
            getTimeDiff(returningInfo, instanceVector);
            if (!returningInfo.empty()) {
                std::cout << "Data\n" << returningInfo.toString() << std::endl;
                result.clear();
                result.push_back(returningInfo);
            }
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

    void VirtualTable::getTimeDiff( Information::Information & returningInfo,
                                    infoVec instanceVector) {
        if (instanceVector.size() == 0) {
            returningInfo = Information::Information{};
            return;
        } else if (instanceVector.size() == 1) {
            returningInfo = *instanceVector.begin();
            return;
        }

        if (returningInfo.empty()) {
            // Avoid redefinition
            returningInfo = *instanceVector.begin();
        }

        struct std::tm tm1{};
        struct std::tm tm2{};
        std::vector<Information::Information>::iterator infoIt = instanceVector.begin();
        while (infoIt != instanceVector.end()) {

            // get values from time
            strptime(returningInfo.GetInfoTimeStamp().c_str(), 
                    std::string(Information::TIME_FORMAT).c_str(),
                    &tm1);
            strptime(infoIt->GetInfoTimeStamp().c_str(), 
                    std::string(Information::TIME_FORMAT).c_str(),
                    &tm2);

            double timeDiff = mktime(&tm1) - mktime(&tm2);
            // Is most recent older than current iterator?
            // > 0 : Most recent is the actual most recent
            // < 0 : Most recent happened before infoIt
            if (timeDiff < 0) {
                std::cout << "Change: \n" << infoIt->toString() << std::endl;
                returningInfo = *infoIt;
            }
            ++infoIt;
        }
    }
} // Namespace LocalMachine