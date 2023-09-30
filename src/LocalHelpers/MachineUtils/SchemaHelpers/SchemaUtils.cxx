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

#include "SchemaUtils.hxx"

#include <MachineUtils.hxx>
#include <Machine.hxx>

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
    
    SCHEMA_MAP SchemaUtils::s_schemaMap {
        std::make_pair(std::string(UNKNOWN_TYPE),
        std::string(UNKNOWN_SCHEMA)),
        std::make_pair(std::string(ANALOG_TYPE),
        std::string(ANALOG_SCHEMA)),
        std::make_pair(std::string(DIGITAL_TYPE),
        std::string(DIGITAL_SCHEMA))
    };

    Information::Information SchemaUtils::DecompressInfo(void * encryptedInfo) {
        return Information::Information{};
    }

    void * SchemaUtils::DecryptInfo(void * encryptedInfo) {
        return nullptr;
    }

    void * SchemaUtils::EncryptCompressedData(void * compressedInfo) {
        return nullptr;
    }

    void * SchemaUtils::CompressData(Information::Information * data) {
        // Check if information is correct, creates pointer to stored info
        if (data->GetInfoId() == Information::DEFAULT_ID) {
            return nullptr; //Nothing to store, TODO get logging going
        } else if (data->GetInfoValue() == Information::DEFAULT_VALUE) {
            return nullptr; //Nothing to store, TODO get logging going
        }
        int32_t infoDataType = data->GetDataType();
        std::string schemaPath = GetSchema(infoDataType);

        // Sanity Check
        if (schemaPath == LocalMachine::UNKNOWN_TYPE) {
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
            if (!IsStringType<int32_t>(data->GetInfoValue())) {
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
    
    /**
     * @brief Gets correct schema location, tests it and returns it
     * 
     * @param[in] inputType value recognizing if it is ANALOG or DIGITAL
    */
    std::string SchemaUtils::GetSchema(int32_t inputType) {
        std::cout << "InputType: "<< inputType << std::endl;
        std::string globalFile = Machine::GetGlobalFile();
        std::string unknownSchemaFileName = s_schemaMap.find(std::string(UNKNOWN_TYPE))->second;
        std::string unknownSchema = globalFile + unknownSchemaFileName;
        // Only the error schema
        if (s_schemaMap.size() == 1) {
            // TODO - Log empty
            return unknownSchema;
        }
        std::string typeName = MachineUtils::GetType(inputType);
        if (!SchemaExists(typeName)){
            return unknownSchema;
        }
        std::string schemaName = s_schemaMap.find(typeName)->second;
        std::string schemaLocation = globalFile + schemaName;
        std::cout << "Schema name: " << schemaName << ", Location: " << schemaLocation << std::endl;
        // Should throw an exception
        CheckSchema(schemaLocation);
        return schemaLocation;
    }

    /** 
     * @brief Called after creating entry in typeMap
     * 
     * @param[in] schemaName Name of the schema, will be checked
     * @param[in] schemaLocation If the schema can be created, will be included
     * 
     * @return success of creation
     * 
     * @note global file path is added to the location in GetSchema output
     * 
     */ 
    bool SchemaUtils::CreateSchema(std::string schemaName, std::string schemaLocation) {
        if (!SchemaExists(schemaName)) {
            return false;
        }
        s_schemaMap[schemaName] = schemaLocation;
        return true;
    }

    bool SchemaUtils::CheckSchema(std::string schemaLoc) {
        // For sanity check
        std::ifstream input(schemaLoc);

        avro::ValidSchema dataSchema;
        avro::compileJsonSchema(input, dataSchema);
        return true;
    }

    bool SchemaUtils::SchemaExists(std::string schemaName) {
        SCHEMA_MAP::iterator it = s_schemaMap.find(schemaName);
        if (it == s_schemaMap.end()) {
            // TODO - Log not existant
            return false;
        }
        return true;
    }
};
