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

            Information::Information DecompressInfo(void * encryptedInfo);

            void * DecryptInfo(void * encryptedInfo);

            void * EncryptCompressedData(void * compressedInfo);

            std::string CompressData(Information::Information * data);

            bool SaveData(Message::BaseMsg message, Information::Information data);

            bool SaveData(Information::Information data);

            std::filesystem::path GetSchema(int32_t inputType);

        private:

            bool CheckSchema(std::string schemaLoc);

            bool SchemaExists(std::string schemaName);

            std::string StoreData(int32_t inputType, LocalMachine::BUFFER_MAP * buffer);

            static SCHEMA_MAP s_schemaMap;

            static std::shared_ptr<LocalMachine::VirtualTable> virtualTable;

    };

}
