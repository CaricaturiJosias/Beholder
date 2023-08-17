/**
 * @file MachineUtils.h
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

#include "../../MessageProcessing/Actors/Sender.hpp"
#include "../../DataModels/Information/Information.hpp"
#include "../../DataModels/MsgInfo/MsgInfo.hpp"
#include "../VirtualTable/VirtualTable.hpp"

namespace LocalMachine {

enum EventType {
    Something // TODO
};

class MachineUtils { //  Acts like an interface

    public:
    
        bool CheckPermission(std::string command, Sender sender);

        Information DecompressInfo(void * encryptedInfo);

        void * DecryptInfo(void * encryptedInfo);

        void * EncryptCompressedData(void * compressetInfo);

        void * CompressData(MsgInfo data);

        double GetRecordsAmmount();

        bool DataLookUp(MsgInfo data);

        bool hasSpace(void * encryptedData);

        void LogEvent(std::string msg, EventType eventType);

        bool SaveData(void * data);

        bool SaveData(MsgInfo data);

        void UpdateTable(void * data, double dataOwner);

        MsgInfo LookUpData(MsgInfo data);

        VirtualTable GetVirtualTable();

        std::vector<Information> GetDataInArray(MsgInfo dataInfo);

};

}
