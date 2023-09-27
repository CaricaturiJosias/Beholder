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

// TODO - Use Avro here for data storing, temporary types here
typedef std::string storedValue;
typedef int storageId;

VirtualTable * VirtualTable::GetInstance() {
    return new VirtualTable();
}

VirtualTable::VirtualTable() {
    // TODO
}

VirtualTable::~VirtualTable() {
    // Nothing
}

keyMap VirtualTable::GetKeyMap() {
    return keyMap{};
}

valueMap VirtualTable::GetValueMap() {
    return valueMap{};
}

void * VirtualTable::GetStoredValue(storageId id) {
    return nullptr;
}

double VirtualTable::numRows = 0;

keyMap VirtualTable::dataMapKey = keyMap();
valueMap VirtualTable::dataMapValue = valueMap();

VirtualTable * VirtualTable::table = nullptr;

} // Namespace LocalMachine