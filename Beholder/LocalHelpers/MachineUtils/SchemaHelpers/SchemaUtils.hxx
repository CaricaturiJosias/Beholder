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
#include <cstdint>
#include <filesystem>

#include <Information.hxx>
#include <BaseMsg.hxx>
#include <VirtualTable.hxx>
#include <Entity.hxx>

namespace LocalMachine {

    typedef std::map<std::string,std::string> SCHEMA_MAP;

    class SchemaUtils { //  Acts like an interface

        public:

            SchemaUtils();

            static Information::Information DecompressInfo(void * encryptedInfo);

            static void * DecryptInfo(void * encryptedInfo);

            static void * EncryptCompressedData(void * compressedInfo);

            static std::string CompressData(Information::Information * data);

            static bool SaveData(Message::BaseMsg message, Information::Information data);

            static bool SaveData(Information::Information data);

            static std::filesystem::path GetSchema(int32_t inputType);

        private:

            static bool CheckSchema(std::string schemaLoc);

            static bool SchemaExists(std::string schemaName);

            static std::string StoreData(int32_t inputType, LocalMachine::BUFFER_MAP * buffer);

            static SCHEMA_MAP s_schemaMap;

            static std::shared_ptr<LocalMachine::VirtualTable> virtualTable;

    };

}
