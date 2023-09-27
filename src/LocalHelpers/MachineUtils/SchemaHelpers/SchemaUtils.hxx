/**
 * @file SchemaUtils.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Interface to help on schema operations
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string.h>
#include <vector>

#include <Entity.hxx>
#include <Information.hxx>
#include <BaseMsg.hxx>
#include <VirtualTable.hxx>

namespace LocalMachine {

    typedef std::map<std::string,std::string> SCHEMA_MAP;
    
    class SchemaUtils { //  Acts like an interface

        public:

            static Information::Information DecompressInfo(void * encryptedInfo);

            static void * DecryptInfo(void * encryptedInfo);

            static void * EncryptCompressedData(void * compressedInfo);

            static void * CompressData(Information::Information * data);

            static bool SaveData(void * datPointer, Information::Information data);

            static bool SaveData(Information::Information data);

            static std::string GetSchema(int inputType);

            static bool CreateSchema(std::string schemaName, std::string schemaLocation);

        private:

            static bool CheckSchema(std::string schemaLoc);

            static bool SchemaExists(std::string schemaName);

            static SCHEMA_MAP s_schemaMap;

    };

}
