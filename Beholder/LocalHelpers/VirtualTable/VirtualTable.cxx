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

#include "VirtualTable.hxx"

namespace LocalMachine {

    double VirtualTable::numRows = 0;

    valueMap VirtualTable::dataMapValue = valueMap{};

    VirtualTable * VirtualTable::table = nullptr;

    VirtualTable * VirtualTable::GetInstance() {
        if (table == nullptr) {
            table = new VirtualTable();
        }
        return table;
    }

    VirtualTable::VirtualTable() {
        // TODO
    }

    VirtualTable::~VirtualTable() {
        // Nothing
    }

    valueMap VirtualTable::GetValueMap() {
        return dataMapValue;
    }

    fileDataValue VirtualTable::GetStoredValue(keyName id) {
        
        return fileDataValue{};
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
        dataMapValue[valueName] = fileInstance;
        return true;
    }

    bool VirtualTable::StoreValue(  dataFilePath value,
                                    keyName valueName,
                                    EncryptionKey encryptionKey,
                                    int32_t dataType) {
        return true;
    }

} // Namespace LocalMachine