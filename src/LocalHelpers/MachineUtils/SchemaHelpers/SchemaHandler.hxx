/**
 * @file SchemaHandler.hxx
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

constexpr std::string_view ANALOG_SCHEMA = "AnalogData.json";
constexpr std::string_view DIGITAL_SCHEMA = "DigitalData.json";
constexpr std::string_view UNKNOWN_SCHEMA = "ErrorSchema.json";

class SchemaUtils { //  Acts like an interface

    public:

        static Information::Information DecompressInfo(void * encryptedInfo);

        static void * DecryptInfo(void * encryptedInfo);

        static void * EncryptCompressedData(void * compressedInfo);

        static void * CompressData(Information::Information * data);

        static bool SaveData(void * datPointer, Information::Information data);

        static bool SaveData(Information::Information data);

        static std::string getCorrectSchema(Information::DataType inputType);

    private:

        static bool checkSchema(std::string schemaLoc);



};

}
