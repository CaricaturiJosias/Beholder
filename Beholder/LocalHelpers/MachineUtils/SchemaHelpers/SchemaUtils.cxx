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

        
    /**
     * @brief Gets the location of data stored in the database
     * 
     * @param[in] file Location of a file that MAY contain data with the given id
     * @param[in] id Name of the data Id we are looking for (every single one we can find)
     * 
    */
    std::vector<Information::Information> SchemaUtils::GetData(fileDataValue dataInstance, std::string id) {
        std::vector<Information::Information> infosInFile;
        std::vector<Information::Information> foundInfos;
        // std::cout << "Called GetData for id " << id << std::endl;

        infosInFile = DecryptInfo(dataInstance);
        // Identify the information we found
        for (Information::Information singleInfo : infosInFile) {
            if (singleInfo.GetInfoId() == id) {
                foundInfos.push_back(singleInfo);
            }
        }

        return foundInfos;
    }

    std::vector<Information::Information> SchemaUtils::DecryptInfo(fileDataValue fileData) {
        std::vector<Information::Information> result;
        std::string filePath = fileData.data;

        // TODO - Actual decryption
        // filepath should be the path to a encrypted info,
        // lets suppose we decrypted it already for now
        
        // stuff done to decrypt ...
        std::string decryptedPath = filePath;

        // The results should be handled by the caller
        return DecompressInfo(decryptedPath);
    }

    std::vector<Information::Information> SchemaUtils::DecompressInfo(std::string file) {
        std::vector<Information::Information> infoInFile;
        int32_t inputType;
        std::filesystem::path path(file);

        // Extract the file name (including the extension)
        std::string fileName = path.filename().string();
        char prefix = fileName[0];

        if (prefix == 'A') {
            inputType = ANALOG;
        } else if (prefix == 'D') {
            inputType = DIGITAL;
        } else {
            // TODO - Log error message
            std::cout << "Invalid prefix: " << prefix << "On file " << file << std::endl;
            return infoInFile;
        }

        std::ifstream ifs(GetSchema(inputType));
        avro::ValidSchema schemaResult;
        avro::compileJsonSchema(ifs, schemaResult);
        
        bool teste = false;
        
        // std::cout << "Decompressing type " << ((inputType == ANALOG) ? "ANALOG" : "DIGITAL") << std::endl;
        

        if (inputType == ANALOG) {
            avro::DataFileReader<c::Analog> readerInstance(path.c_str(), schemaResult);
            c::Analog analog;

            while(readerInstance.read(analog)) {
                infoInFile.push_back(Information::Information(analog));
            }
            readerInstance.close();
        } else {
            // DIGITAL
            avro::DataFileReader<c::Digital> readerInstance(path.c_str(), schemaResult);
            c::Digital digital;
            while(readerInstance.read(digital)) {
                infoInFile.push_back(Information::Information(digital));
            }
            readerInstance.close();
        }
        return infoInFile;
    }

    valueMap SchemaUtils::GetDataInfoFromFiles(const std::string filePath) {
        // Iterate through the files in the directory
        valueMap outputResult;
        std::pair<std::string, fileDataValue> iteratorInstance;
        for (const auto& entry : std::filesystem::directory_iterator(filePath)) {
            if (entry.is_regular_file()) {
                // std::cout << "Reading " << entry.path().filename() << std::endl;
                iteratorInstance = GetDataInfoFromFile(entry.path().string());
                if (iteratorInstance.second.empty()) {
                    // std::cout << entry.path().filename() << " is empty??" << std::endl;
                    continue;
                }
                std::string idPrefix = ((iteratorInstance.second.dataType == ANALOG) ?
                                            std::string("A") : 
                                            std::string("D"));
                std::string valueId = idPrefix + iteratorInstance.first ;
                outputResult[valueId] = iteratorInstance.second;
            }
        }
        return outputResult;
    }

    std::pair<std::string, fileDataValue> SchemaUtils::GetDataInfoFromFile(const std::string file) {
        std::string fileId; //  Number on the file, used as id
        std::string targetFile; // File to have its name analyzed
        std::string sub_str; // String instance to help identify id of the file

        size_t pos = file.find('_') + 1; // Exclude the _ itself
        // All after _ (like 102.bin)
        sub_str = file.substr(pos);
        pos = sub_str.find(std::string(".bin"));
        fileId = sub_str.substr(0,pos);
        fileDataValue fileData;

        // TODO - TEMPORARY - FIND BETTER WAY TO COLD START IDENTIFY DATA
        std::filesystem::path path(file);

        // Extract the file name (including the extension)
        std::string fileName = path.filename().string();
        char prefix = fileName[0];
        // std::cout << "Found the prefix: " << prefix << " For file " << file << std::endl;
        if (prefix == 'A') {
            fileData = fileDataValue(file, ANALOG);
        } else if (prefix == 'D') {
            fileData = fileDataValue(file, DIGITAL);
        } else {
            return std::make_pair(std::string(""), fileDataValue());
        }
        return std::make_pair(fileId, fileData);
    }

    void * SchemaUtils::EncryptCompressedData(void * compressedInfo) {
        return nullptr;
    }

    std::string SchemaUtils::CompressData(Information::Information * data) {
        // Check if information is correct, creates pointer to stored info
        if (data->GetInfoId() == Information::DEFAULT_ID) {
            return nullptr; 
        } else if (data->GetInfoValue() == Information::DEFAULT_VALUE) {
            return nullptr; 
        }
        int32_t infoDataType = data->GetDataType();
        std::string schemaPath = GetSchema(infoDataType);

        // Sanity Check
        if (schemaPath == LocalMachine::UNKNOWN_TYPE) {
            // Logging for schema error
            // std::cout << "Schema is unknown" << std::endl;
            return nullptr;
        }
        // TODO - Remove
        // std::cout << "Schema is known" << std::endl;
        // Check timestamp value sent, if default define the local system time
        std::string timestamp = data->GetInfoTimeStamp();
        if (timestamp == Information::DEFAULT_TIME) {
            // TODO - Log occurance
            // std::cout << "time is the default time" << std::endl;
            timestamp = LocalMachine::MachineUtils::GetCurrentTime();
        }
        // TODO - Remove
        // std::cout << "Timestamp is valid" << std::endl;
        BUFFER_MAP * buffer = virtualTable->getBuffer();
        BUFFER_MAP::iterator it = buffer->find(infoDataType);

        if (it == buffer->end()) {
            // TODO - Log occurance
            // Does not exist in the information vectors map, error
            // std::cout << "Buffer does not exist" << std::endl;
            return nullptr;
        }

        INFO_LIST currentList = (*buffer)[infoDataType];
        currentList.push_back(informationValue(*data));

        // TODO - Remove
        // std::cout << "Buffer size: " << currentList.size() << std::endl;

        if (LocalMachine::MAX_BUFFER_SIZE == currentList.size()) {
            // TODO - Remove
            // std::cout << "Saving, pushing it into buffer" << std::endl;
            std::string fileStored = StoreData(infoDataType, buffer);
            (*buffer)[infoDataType].clear();
            return fileStored;
        }
        // TODO - Remove
        // std::cout << "Not saving, pushing it into buffer" << std::endl;
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
        // std::cout << "compressed Path : " << compressedPath << std::endl;
        return true;
    }

    /**
     * @brief Gets correct schema location, tests it and returns it
     * 
     * @param[in] inputType value recognizing if it is ANALOG or DIGITAL
    */
    std::filesystem::path SchemaUtils::GetSchema(int32_t inputType) {
        // std::cout << "InputType: "<< inputType << std::endl;
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
        // std::cout << "Schema name: " << schemaName << ", Location: " << schemaLocation << std::endl;
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
            schemaItem.id = infoVal.id;
            schemaItem.timestamp = infoVal.timestamp;
            // std::cout << "Ready to write schema" << std::endl;
            writerInstance.write(schemaItem);
            // std::cout << "Finished writing schema" << std::endl;
        }
        writerInstance.close();
    }

    std::string SchemaUtils::StoreData(int32_t infoDataType, LocalMachine::BUFFER_MAP * buffer) {
        
        std::filesystem::path schemaPath = GetSchema(infoDataType);
        std::ifstream schemaStream(schemaPath);
        char type = (infoDataType == ANALOG) ? 'A' : 'D';

        if (schemaPath == UNKNOWN_TYPE) {
            // LOG - We MUST log this scenario
            // std::cout << "Will not save data" << std::endl;
            return "";
        }
        std::filesystem::path storageLocation(Machine::GetStoragePath());
        std::filesystem::path tempFile;
        bool tempFinished = false;
        while (!tempFinished) {
            // Saving file here
            tempFile = Machine::GetNewTempFile(type);
            // std::cout << "StoreData: Found files: " << i << std::endl;
            if (std::filesystem::exists(tempFile)) {
                // std::cout << "File already exists: " << targetFile << std::endl;
                continue;
                // Will try until we find an unused ID
            }
        }
        // Quick way to check if exists
        if (!std::filesystem::exists(schemaPath)) {
            // Create
            std::filesystem::create_directory(schemaPath);
        }

        avro::ValidSchema schemaResult;
        avro::compileJsonSchema(schemaStream, schemaResult);
        // std::cout << "StoreData: infoDataType = " << infoDataType << std::endl;
        if (infoDataType == ANALOG) {
            c::Analog analog;
            avro::DataFileWriter<c::Analog>
                writerInstance( tempFile.c_str(),
                                schemaResult);
            // std::cout << "StoreData: writing analog"<< std::endl;
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
            // std::cout << "StoreData: writing digital"<< std::endl;
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
            // std::cout << "StoreData: Found files: " << i << std::endl;
            targetFile = Machine::GetNewStorageFile(type);

            if (std::filesystem::exists(targetFile)) {
                // std::cout << "File already exists: " << targetFile << std::endl;
                continue;
                // Will try until we find an unused ID
            }
            saved = true;
            // TODO - Remove
            // std::cout << "Storing data in file " << targetFile << std::endl;
            
            // get ID off of file
            size_t pos = targetFile.find('_') + 1; // Exclude the _ itself

            // All after _ (like 102.bin)
            std::string sub_str = targetFile.substr(pos);
            pos = sub_str.find(std::string(".bin"));
            fileId = sub_str.substr(0,pos);

            // TODO - Remove
            // std::cout << "ID on file " << targetFile << " : " << fileId << std::endl;
            // We have the id

            std::filesystem::copy_file(tempFile, targetFile, std::filesystem::copy_options::overwrite_existing );
        }
        bool success = virtualTable->StoreValue(targetFile, fileId, infoDataType);
        if (success) {
            return targetFile;
        }
        return "";
    }
};
