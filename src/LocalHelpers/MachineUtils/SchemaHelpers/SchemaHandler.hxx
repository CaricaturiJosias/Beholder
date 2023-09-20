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

#include "../../MessageProcessing/Actors/Sender.hxx"
#include "../../DataModels/Information/Information.hxx"
#include "../../DataModels/MsgInfo/MsgInfo.hxx"
#include "../VirtualTable/VirtualTable.hxx"

namespace LocalMachine {

constexpr std::string_view ANALOG_SCHEMA = "./Schemas/AnalogData.json";
constexpr std::string_view DIGITAL_SCHEMA = "./Schemas/DigitalData.json";

class SchemaUtils { //  Acts like an interface

    public:

        static Information DecompressInfo(void * encryptedInfo);

        static void * DecryptInfo(void * encryptedInfo);

        static void * EncryptCompressedData(void * compressedInfo);

        static void * CompressData(Information::Information data);

        static bool SaveData(void * datPointer, Information::Information data);

        static bool SaveData(Information::Information data);


    private:

        static bool checkSchema(std::string schemaLoc);


};

}
