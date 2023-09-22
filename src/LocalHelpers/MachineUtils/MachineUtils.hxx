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

#include "../../Entities/Base/Entity.hxx"
#include "../../DataModels/Information/Information.hxx"
#include "../../DataModels/Msg/Base/BaseMsg.hxx"
#include "../VirtualTable/VirtualTable.hxx"

namespace LocalMachine {

enum EventType {
    Something // TODO
};

class MachineUtils { //  Acts like an interface

    public:
    
        bool CheckPermission(std::string command, Sender sender);

        Information::Information DecompressInfo(void * encryptedInfo);

        void * DecryptInfo(void * encryptedInfo);

        void * EncryptCompressedData(void * compressetInfo);

        void * CompressData(Message::BaseMsg data);

        double GetRecordsAmmount();

        bool DataLookUp(Message::BaseMsg data);

        bool hasSpace(void * encryptedData);

        void LogEvent(std::string msg, EventType eventType);

        bool SaveData(void * data);

        bool SaveData(Message::BaseMsg data);

        void UpdateTable(void * data, double dataOwner);

        Information::Information LookUpData(Information::Information data);

        VirtualTable GetVirtualTable();

        std::vector<Information::Information> GetDataInArray(Message::BaseMsg dataInfo);

        std::string GetCurrentTime();
};

}
