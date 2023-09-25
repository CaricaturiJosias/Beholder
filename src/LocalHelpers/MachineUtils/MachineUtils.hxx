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

#include <Entity.hxx>
#include <Information.hxx>
#include <BaseMsg.hxx>
#include <VirtualTable.hxx>

namespace LocalMachine {

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

            static bool DataLookUp(Message::BaseMsg data);

            static bool hasSpace(void * encryptedData);

            static void LogEvent(std::string msg, EventType eventType);

            static bool SaveData(void * data);

            static bool SaveData(Message::BaseMsg data);

            static void UpdateTable(void * data, double dataOwner);

            static Information::Information LookUpData(Message::BaseMsg data);

            static VirtualTable GetVirtualTable();

            static std::vector<Information::Information> GetDataInArray(Message::BaseMsg dataInfo);

            static std::string GetCurrentTime();

            static bool IsStringInt(std::string value);

    };

}
