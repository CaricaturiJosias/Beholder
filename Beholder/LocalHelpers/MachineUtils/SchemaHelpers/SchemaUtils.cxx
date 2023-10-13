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

#include <VirtualTable.hxx>
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

    std::shared_ptr<LocalMachine::VirtualTable> SchemaUtils::virtualTable = nullptr;

    SchemaUtils::SchemaUtils() {
        virtualTable = LocalMachine::VirtualTable::GetInstance();
    }

    Information::Information SchemaUtils::DecompressInfo(void * encryptedInfo) {
        return Information::Information{};
    }

    void * SchemaUtils::DecryptInfo(void * encryptedInfo) {
        return nullptr;
    }

    void * SchemaUtils::EncryptCompressedData(void * compressedInfo) {
        return nullptr;
    }

    std::string SchemaUtils::CompressData(Information::Information * data) {
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
        // TODO - Remove
        std::cout << "Schema is known" << std::endl;
        // Check timestamp value sent, if default define the local system time
        std::string timestamp = data->GetInfoTimeStamp();
        if (timestamp == Information::DEFAULT_TIME) {
            // TODO - Log occurance
            std::cout << "time is the default time" << std::endl;
            timestamp = LocalMachine::MachineUtils::GetCurrentTime();
        }
        // TODO - Remove
        std::cout << "Timestamp is valid" << std::endl;
        BUFFER_MAP * buffer = virtualTable->getBuffer();
        BUFFER_MAP::iterator it = buffer->find(infoDataType);

        if (it == buffer->end()) {
            // TODO - Log occurance
            // Does not exist in the information vectors map, error
            std::cout << "Buffer does not exist" << std::endl;
            return nullptr;
        }

        INFO_LIST currentList = (*buffer)[infoDataType];
        currentList.push_back(informationValue(*data));

        // TODO - Remove
        std::cout << "Buffer size: " << currentList.size() << std::endl;

        if (LocalMachine::MAX_BUFFER_SIZE == currentList.size()) {
            // TODO - Remove
            std::cout << "Saving, pushing it into buffer" << std::endl;
            std::string fileStored = StoreData(infoDataType, buffer);
            (*buffer)[infoDataType].clear();
            return fileStored;
        }
        // TODO - Remove
        std::cout << "Not saving, pushing it into buffer" << std::endl;
        (*buffer)[infoDataType].push_back(informationValue(*data));

        return "";
    }

    bool SchemaUtils::SaveData(Message::BaseMsg message, Information::Information data) {
        return true;
    }

    bool SchemaUtils::SaveData(Information::Information data) {
        if (data.empty()) {
            // Log error
            return false;
        }
        std::string compressedPath = CompressData(&data);
        std::cout << "compressed Path : " << compressedPath << std::endl;
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

    std::string SchemaUtils::StoreData(int32_t infoDataType, LocalMachine::BUFFER_MAP * buffer) {
        
        std::filesystem::path schemaPath = GetSchema(infoDataType);
        std::ifstream schemaStream(schemaPath);

        if (schemaPath == UNKNOWN_TYPE) {
            // LOG - We MUST log this scenario
            std::cout << "Will not save data" << std::endl;
            return "";
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
                        (*buffer)[infoDataType],
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
                        (*buffer)[infoDataType],
                        infoDataType);
        }
        int i = 0;
        bool saved = false;
        std::string targetFile;
        std::string fileId;

        while (!saved) {
            // Saving file here
            i = LocalMachine::Machine::GetAmmountOfFiles();
            targetFile = Machine::GetNewStorageFile();

            if (std::filesystem::exists(targetFile)) {
                std::cout << "File already exists: " << targetFile << std::endl;
                continue;
                // Will try until we find an unused ID
            }
            saved = true;
            // TODO - Remove
            std::cout << "Storing data in file " << targetFile << std::endl;
            
            // get ID off of file
            size_t pos = targetFile.find('_') + i; // Exclude the _ itself
            // All after _ (like 102.bin)
            std::string sub_str = targetFile.substr(pos);
            pos = sub_str.find(std::string(".bin"));
            fileId = sub_str.substr(0,pos);

            // TODO - Remove
            std::cout << "ID on file " << targetFile << " : " << fileId << std::endl;
            // We have the id

            std::filesystem::copy_file(tempFile, targetFile, std::filesystem::copy_options::overwrite_existing );
        }
        bool success = virtualTable->StoreValue(targetFile, fileId, infoDataType);
        return targetFile;
    }
};
