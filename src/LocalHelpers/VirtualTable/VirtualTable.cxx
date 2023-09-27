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

    EncryptedValue VirtualTable::GetStoredValue(keyName id) {
        
        return std::shared_ptr<dataPointer>(nullptr);
    }

    bool VirtualTable::StoreValue(dataPointer value, keyName valueName) {
        if (value == nullptr) {
            // TODO - LOG error
            return false;
        }

        valueMap::iterator it = dataMapValue.find(valueName);
        if (it != dataMapValue.end()) {
            // TODO - Log existing value
            return false;
        }
        EncryptedValue valueToSave = std::make_shared<dataPointer>(value);
        dataMapValue.insert(valueName, valueToSave);
        return true;
    }

} // Namespace LocalMachine