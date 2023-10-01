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

namespace LocalMachine {

    double Machine::memory = 0;

    std::string Machine::virtualTablePath = "./";

    std::string Machine::GetStoragePath () {
        std::string systemFile;
        #ifdef __linux__
            systemFile = "/usr/local/beholder/";
        #elif _WIN32
            // TODO - SCAVANGE WINDOWS INFO WHEN ITS THE TARGET DISTRO
            systemFile = "C:\\Users\\YourUsername\\Documents\\Project\\schema\\";
        #endif
        return systemFile;
    }

    std::string Machine::GetGlobalFile() {
        std::string systemFile;
        #ifdef __linux__
            systemFile = "/usr/lib/schema/";
        #elif _WIN32
            // TODO - SCAVANGE WINDOWS INFO WHEN ITS THE TARGET DISTRO
            systemFile = "C:\\Users\\YourUsername\\Documents\\Project\\schema\\";
        #endif
        return systemFile;
    }

}; // Namespace
