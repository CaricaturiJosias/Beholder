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
#include <ffstream>
#include <vector>

#include "./GeneratedHeaders/AnalogData.hh"
#include "./GeneratedHeaders/DigitalData.hh"

#include "../../../Entities/Base/Entity.hxx"
#include "../../../DataModels/Information/Information.hxx"
#include "../../VirtualTable/VirtualTable.hxx"

#include "SchemaHandler.hxx"

// Apache Avro related imports
#include <avro/ValidSchema.hh>
#include <avro/Compiler.hh>
#include <avro/Decoder.hh>
#include <avro/Encoder.hh>

namespace LocalMachine {
        

    
    Information::Information SchemaUtils::DecompressInfo(void * encryptedInfo) {

    }

    void * SchemaUtils::DecryptInfo(void * encryptedInfo) {

    }

    void * SchemaUtils::EncryptCompressedData(void * compressedInfo) {

    }

    void * SchemaUtils::CompressData(Information::Information * data) {
        // Check if information is correct, creates pointer to stored info
        if (data->getInfoId() == Information::DEFAULT_ID) {
            return nullptr; //Nothing to store, TODO get logging going
        } else if (data->getInfoValue() == Information::DEFAULT_VALUE) {
            return nullptr; //Nothing to store, TODO get logging going
        }

        std::string schemaPath;
        if (data->getDataType == Information::ANALOG) {
            schemaPath = LocalMachine::ANALOG_SCHEMA;
        } else {
            schemaPath = LocalMachine::DIGITAL_SCHEMA;
        }

        // Create handler for serialization encoding
        std::unique_ptr<avro::OutputStream> out = avro::memoryOutputStream();
        avro::EncoderPtr e = avro::binaryEncoder();
    }

    bool SchemaUtils::SaveData(void * dataPointer, Information::Information data) {

    }

    bool SchemaUtils::SaveData(Information::Information data) {

    }

    bool SchemaUtils::checkSchema(std::string schemaLoc) {
        // For sanity check
        std::ifstream input(schemaLoc);

        avro::ValidSchema dataSchema;
        avro::compileJsonSchema(input, dataSchema);
    }

};
