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
#include <MachineUtils.hxx>

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