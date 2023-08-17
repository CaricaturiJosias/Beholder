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

#pragma once

#include <map>

namespace LocalMachine {

// TODO - Use avros here for data storing, temporary types here
typedef std::string storedValue;
typedef double storageId;

typedef std::map<double, std::string> keyMap;
typedef std::map<double, std::string> valueMap;

class VirtualTable {

    public:
        VirtualTable * GetInstance();

        VirtualTable();
        ~VirtualTable();

        keyMap GetKeyMap();
        valueMap GetValueMap();

        storedValue * GetStoredValue(storageId id);

    private:
        
        double numRows;

        keyMap dataMapKey;
        valueMap dataMapValue;

        VirtualTable * table;
};

} // Namespace LocalMachine