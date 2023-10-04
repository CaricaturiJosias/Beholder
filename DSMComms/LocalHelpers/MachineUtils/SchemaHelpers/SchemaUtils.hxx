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

#include <Entity.hxx>
#include <Information.hxx>
#include <BaseMsg.hxx>
#include <VirtualTable.hxx>

namespace LocalMachine {

    typedef std::map<std::string,std::string> SCHEMA_MAP;

    struct informationValue {
        std::string id;
        std::string value;
        std::string quality;
        std::string timestamp;

        informationValue (Information::Information info) {
            id = info.GetInfoId();
            id.shrink_to_fit();
            value = info.GetInfoValue();
            value.shrink_to_fit();
            quality = info.GetInfoQuality();
            quality.shrink_to_fit();
            timestamp = info.GetInfoTimeStamp();
            timestamp.shrink_to_fit();
        }
    };

    typedef std::vector<informationValue> INFO_LIST;
    typedef std::map<int32_t, INFO_LIST> BUFFER_MAP;

    class SchemaUtils { //  Acts like an interface

        public:

            static Information::Information DecompressInfo(void * encryptedInfo);

            static void * DecryptInfo(void * encryptedInfo);

            static void * EncryptCompressedData(void * compressedInfo);

            static void * CompressData(Information::Information * data);

            static bool SaveData(void * dataPointer, Information::Information data);

            static bool SaveData(Information::Information data);

            static std::filesystem::path GetSchema(int32_t inputType);

        private:

            static bool CheckSchema(std::string schemaLoc);

            static bool SchemaExists(std::string schemaName);

            static bool StoreData(int32_t inputType);

            static SCHEMA_MAP s_schemaMap;

            static BUFFER_MAP s_infoBuffer;

            static uint32_t MAX_BUFFER_SIZE;

    };

}
