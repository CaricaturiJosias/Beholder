/**
 * @file MachineUtils.hxx
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
#include <cstdint>
#include <map>

#include <Entity.hxx>
#include <Information.hxx>
#include <BaseMsg.hxx>
#include <VirtualTable.hxx>

namespace LocalMachine {

    constexpr std::string_view UNKNOWN_TYPE {"UNKNOWN"};
    constexpr std::string_view ANALOG_TYPE {"ANALOG"};
    constexpr std::string_view DIGITAL_TYPE {"DIGITAL"};
    // Defaults
    constexpr std::string_view UNKNOWN_SCHEMA {"ErrorSchema.json"};
    constexpr std::string_view ANALOG_SCHEMA = "AnalogData.json";
    constexpr std::string_view DIGITAL_SCHEMA = "DigitalData.json";

    typedef std::map<int32_t, std::string> DataType;
    const int32_t UNKNOWN = 0;
    const int32_t ANALOG = 1;
    const int32_t DIGITAL = 2;

    enum EventType {
        Something // TODO
    };

    class MachineUtils { //  Acts like an interface

        public:
        
            static bool CheckPermission(std::string command, Entity::Entity sender);

            static Information::Information DecompressInfo(void * encryptedInfo);

            static void * DecryptInfo(void * encryptedInfo);

            static void * EncryptCompressedData(void * compressetInfo);

            static void * CompressData(Message::BaseMsg data);

            static double GetRecordsAmmount();

            static bool hasSpace(void * encryptedData);

            static void LogEvent(std::string msg, EventType eventType);

            static bool SaveData(void * data);

            static bool SaveData(Message::BaseMsg data);

            static bool SaveData(std::string filePath);

            static void UpdateTable(void * data, Entity::Entity dataOwner);

            static Information::Information LookUpData(Message::BaseMsg data);

            static VirtualTable GetVirtualTable();

            static std::vector<Information::Information> GetDataInArray(Message::BaseMsg dataInfo);

            static std::string GetCurrentTime();

            static std::string GetType(int32_t typeValue);
            
        private:

            static DataType typeMap;
    };

}
