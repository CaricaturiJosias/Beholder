/**
 * @file Machine.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdint>
#include <filesystem>

namespace LocalMachine {

    class Machine {

        private:

            static double memory;

            static int32_t fileAmmount;

            static std::string virtualTablePath;

        public: 

            static double GetMemory() { return memory; }

            static std::string GetVirtualTablePath() { return virtualTablePath; }

            static std::filesystem::path GetStoragePath();

            static std::filesystem::path GetGlobalFile();

            static std::string GetNewStorageFile();

            static int32_t GetAmmountOfFiles() { return fileAmmount; }

            static void NewDataFile() { ++fileAmmount;}

    };

}; // Namespace