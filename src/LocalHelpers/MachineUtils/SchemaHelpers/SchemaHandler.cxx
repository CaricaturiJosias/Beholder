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

#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "AnalogData.hh"
#include "DigitalData.hh"

#include "SchemaHandler.hxx"

#include <MachineUtils.hxx>

// Apache Avro related imports
#include <avro/ValidSchema.hh>
#include <avro/Compiler.hh>
#include <avro/Decoder.hh>
#include <avro/Encoder.hh>

#include <time.h>

// Doest belong to the class because contains template
template<typename Number>
bool IsStringType(std::string value) {
    Number n;
    std::string::iterator it = value.begin();
    return((std::istringstream(value) >> n >> std::ws).eof());
}

namespace LocalMachine {
        

    
    Information::Information SchemaUtils::DecompressInfo(void * encryptedInfo) {
        return Information::Information{};
    }

    void * SchemaUtils::DecryptInfo(void * encryptedInfo) {
        return nullptr;
    }

    void * SchemaUtils::EncryptCompressedData(void * compressedInfo) {
        return nullptr;
    }

    /**
     * @brief Gets correct schema location, tests it and returns it
     * 
     * @param[in] inputType value recognizing if it is ANALOG or DIGITAL
    */
    std::string SchemaUtils::getCorrectSchema(Information::DataType inputType) {
        std::string schemaLocation;
        switch (inputType) {
            case Information::ANALOG:
                schemaLocation = LocalMachine::ANALOG_SCHEMA;
                break;
            case Information::DIGITAL:
                schemaLocation = LocalMachine::DIGITAL_SCHEMA;
                break;
            default:
                schemaLocation = LocalMachine::UNKNOWN_SCHEMA;
                break;
        }
        // Should throw an exception
        checkSchema(schemaLocation);
        return schemaLocation;
    }

    void * SchemaUtils::CompressData(Information::Information * data) {
        // Check if information is correct, creates pointer to stored info
        if (data->GetInfoId() == Information::DEFAULT_ID) {
            return nullptr; //Nothing to store, TODO get logging going
        } else if (data->GetInfoValue() == Information::DEFAULT_VALUE) {
            return nullptr; //Nothing to store, TODO get logging going
        }
        Information::DataType infoDataType = data->GetDataType();
        std::string schemaPath = getCorrectSchema(infoDataType);

        // Sanity Check
        if (schemaPath == LocalMachine::UNKNOWN_SCHEMA) {
            // Logging for schema error
            return nullptr;
        }

        // Check timestamp value sent, if default define the local system time
        std::string timestamp = data->GetInfoTimeStamp();
        if (timestamp == Information::DEFAULT_TIME) {
            // TODO - Log occurance
            timestamp = LocalMachine::MachineUtils::GetCurrentTime();
        }

        // Create handler for serialization encoding
        std::unique_ptr<avro::OutputStream> out = avro::memoryOutputStream();
        avro::EncoderPtr encoder = avro::binaryEncoder();

        // Encoding necessary for each
        if (infoDataType == Information::ANALOG) {
            if (!IsStringType<double>(data->GetInfoValue())) {
                // Log number is not valid
                return nullptr;
            }
            encoder->init(*out);
            c::Analog analog;
            analog.value = std::stod(data->GetInfoValue());
            avro::encode(*encoder, analog);   
        } else {
            // DIGITAL
            if (!IsStringType<int>(data->GetInfoValue())) {
                // Log number is not valid
                return nullptr;
            }
            encoder->init(*out);
            c::Analog analog;
            analog.value = std::stoi(data->GetInfoValue());
            avro::encode(*encoder, analog); 
        }
        // Will be encrypted
        return static_cast<void *>(encoder.get());
    }

    bool SchemaUtils::SaveData(void * dataPointer, Information::Information data) {
        return true;
    }

    bool SchemaUtils::SaveData(Information::Information data) {
        return true;
    }

    bool SchemaUtils::checkSchema(std::string schemaLoc) {
        // For sanity check
        std::ifstream input(schemaLoc);

        avro::ValidSchema dataSchema;
        avro::compileJsonSchema(input, dataSchema);
        return true;
    }

};
