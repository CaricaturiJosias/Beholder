/**
 * @file Machine.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Machine.hxx"

#include <cstdlib>
#include <sys/stat.h>
#include <fstream>
#include <string> // stod, stoi, etc.

namespace LocalMachine {

    double Machine::memory = 0;

    int32_t Machine::fileAmmount = 0;

    std::shared_ptr<VirtualTable> Machine::s_virtualTable = nullptr;

    std::shared_ptr<VirtualTable> Machine::GetVirtualTable() {
        if (s_virtualTable == nullptr) {
            s_virtualTable = LocalMachine::VirtualTable::GetInstance();
        }
        return s_virtualTable;
    }

    std::filesystem::path Machine::GetStoragePath () {
        std::filesystem::path systemFile;
        #ifdef __linux__
            std::string homePath = std::getenv("HOME");
            systemFile = homePath + "/beholder/";
        #elif _WIN32
            // TODO - SCAVANGE WINDOWS INFO WHEN ITS THE TARGET DISTRO
            systemFile = "C:\\Users\\YourUsername\\Documents\\Project\\schema\\";
        #endif
        if (!std::filesystem::exists(systemFile)) {
            std::filesystem::create_directory(systemFile);
        }
        return systemFile;
    }

    std::filesystem::path Machine::GetGlobalFile() {
        std::filesystem::path systemFile;
        #ifdef __linux__
            std::string homePath = std::getenv("HOME");
            systemFile = homePath + "/schema/";
        #elif _WIN32
            // TODO - SCAVANGE WINDOWS INFO WHEN ITS THE TARGET DISTRO
            systemFile = "C:\\Users\\YourUsername\\Documents\\Project\\schema\\";
        #endif
        if (!std::filesystem::exists(systemFile)) {
            std::filesystem::create_directory(systemFile);
        }
        return systemFile;
    }

    std::string Machine::GetNewStorageFile() {
        std::filesystem::path storagePath = GetStoragePath();
        std::string storageFile{storagePath.generic_string() + "data_" + std::to_string(GetAmmountOfFiles()) + ".bin"};
        std::cout << "Ammount of files: " << std::to_string(GetAmmountOfFiles()) << std::endl;
        // Update the counter
        NewDataFile();        
        return storageFile;
    }
}; // Namespace
