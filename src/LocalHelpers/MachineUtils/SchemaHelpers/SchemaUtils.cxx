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
#include <avro/DataFile.hh>
#include "avro/Generic.hh"

#include <sys/stat.h>
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

    std::map<int32_t, INFO_LIST> SchemaUtils::s_infoBuffer = {
        {ANALOG, {}},
        {DIGITAL, {}}
    };

    uint32_t SchemaUtils::MAX_BUFFER_SIZE = 1;

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
            std::cout << "Schema is unknown" << std::endl;
            return nullptr;
        }
        std::cout << "Schema is known" << std::endl;
        // Check timestamp value sent, if default define the local system time
        std::string timestamp = data->GetInfoTimeStamp();
        if (timestamp == Information::DEFAULT_TIME) {
            // TODO - Log occurance
            std::cout << "time is the default time" << std::endl;
            timestamp = LocalMachine::MachineUtils::GetCurrentTime();
        }
        std::cout << "Timestamp is valid" << std::endl;
        if (!s_infoBuffer.count(infoDataType)) {
            // TODO - Log occurance
            // Does not exist in the information vectors map, error
            std::cout << "Buffer does not exist" << std::endl;
            return nullptr;
        }

        INFO_LIST currentList = s_infoBuffer[infoDataType];
        currentList.push_back(informationValue(*data));
        std::cout << "Buffer size: " << currentList.size() << std::endl;

        if (MAX_BUFFER_SIZE == currentList.size()) {
            std::cout << "Saving, pushing it into buffer" << std::endl;
            StoreData(infoDataType);
            s_infoBuffer.clear();
            return nullptr;
        }
        // TODO - Proper logging
        std::cout << "Not saving, pushing it into buffer" << std::endl;
        return nullptr;
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
    std::filesystem::path SchemaUtils::GetSchema(int32_t inputType) {
        std::cout << "InputType: "<< inputType << std::endl;
        std::filesystem::path globalFile = Machine::GetGlobalFile();
        std::string unknownSchemaFileName = s_schemaMap.find(std::string(UNKNOWN_TYPE))->second;
        // Only the error schema
        if (s_schemaMap.size() == 1) {
            // TODO - Log empty
            return unknownSchemaFileName;
        }
        std::string typeName = MachineUtils::GetType(inputType);
        if (!SchemaExists(typeName)){
            return unknownSchemaFileName;
        }
        std::string schemaName = s_schemaMap.find(typeName)->second;
        std::filesystem::path schemaLocation = globalFile / schemaName;
        std::cout << "Schema name: " << schemaName << ", Location: " << schemaLocation << std::endl;
        // Should throw an exception if json is non existent
        CheckSchema(schemaLocation);
        return schemaLocation;
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

    template<typename T>
    void populateWriter(avro::DataFileWriter<T> &writerInstance,
                        T schemaItem,
                        INFO_LIST infoMap,
                        int32_t type) {
        for (informationValue infoVal : infoMap) {
            schemaItem.value = (type == ANALOG) ? std::stod(infoVal.value) : std::stoi(infoVal.value);
            schemaItem.quality = std::stoi(infoVal.quality);
            schemaItem.id = std::stod(infoVal.id);
            schemaItem.timestamp = infoVal.timestamp;
            writerInstance.write(schemaItem);
        }
        writerInstance.close();
    }

    bool SchemaUtils::StoreData(int32_t infoDataType) {
        
        struct stat buffer; 
        std::filesystem::path schemaPath = GetSchema(infoDataType);
        std::ifstream schemaStream(schemaPath);

        if (schemaPath == UNKNOWN_TYPE) {
            // LOG - We MUST log this scenario
            std::cout << "Will not save data" << std::endl;
            return false;
        }
        std::filesystem::path storageLocation(Machine::GetStoragePath());
        std::filesystem::path tempFile = storageLocation / "data.tmp";

        // Quick way to check if exists
        if (!std::filesystem::exists(schemaPath)) {
            // Create
            std::filesystem::create_directory(schemaPath);
        }

        avro::ValidSchema schemaResult;
        avro::compileJsonSchema(schemaStream, schemaResult);

        if (infoDataType == ANALOG) {
            c::Analog analog;
            avro::DataFileWriter<c::Analog>
                writerInstance( tempFile.c_str(),
                                schemaResult);
            populateWriter<c::Analog>(
                        writerInstance,
                        analog,
                        s_infoBuffer[infoDataType],
                        infoDataType);
        } else {
            // DIGITAL
            c::Digital digital;
            avro::DataFileWriter<c::Digital>
            writerInstance(
                tempFile.c_str(),
                schemaResult);
            populateWriter<c::Digital>(
                        writerInstance,
                        digital,
                        s_infoBuffer[infoDataType],
                        infoDataType);
        }
        // Saving file here
        std::string targetFile = Machine::GetNewStorageFile();
        
        std::cout << "Storing data in file " << targetFile << std::endl;

        std::filesystem::copy_file(tempFile, targetFile, std::filesystem::copy_options::overwrite_existing );
        
        return true;
    }
};
