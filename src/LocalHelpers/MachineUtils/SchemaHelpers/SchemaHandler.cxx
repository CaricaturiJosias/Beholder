/**
 * @file SchemaUtils.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string.h>
#include <vector>

#include "./GeneratedHeaders/AnalogData.hh"
#include "./GeneratedHeaders/DigitalData.hh"

#include "../../MessageProcessing/Actors/Sender.hxx"
#include "../../DataModels/Information/Information.hxx"
#include "../../DataModels/MsgInfo/MsgInfo.hxx"
#include "../VirtualTable/VirtualTable.hxx"

// Apache Avro related imports
#include <avro/Decoder.hh>
#include <avro/Encoder.hh>


namespace LocalMachine {

enum EventType {
    Something // TODO
};

class SchemaUtils { //  Acts like an interface

    public:

        Information SchemaUtils::DecompressInfo(void * encryptedInfo) {

        }

        void * SchemaUtils::DecryptInfo(void * encryptedInfo) {

        }

        void * SchemaUtils::EncryptCompressedData(void * compressetInfo) {

        }

        void * SchemaUtils::CompressData(MsgInfo data) {

        }

        bool SchemaUtils::SaveData(void * data, DataType dataType); {

        }

        bool SchemaUtils::SaveData(MsgInfo data) {

        }

};

}
