/**
 * @file SchemaUtils.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Interface to help on schema operations
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string.h>
#include <vector>

#include "../../MessageProcessing/Actors/Sender.hxx"
#include "../../DataModels/Information/Information.hxx"
#include "../../DataModels/MsgInfo/MsgInfo.hxx"
#include "../VirtualTable/VirtualTable.hxx"

namespace LocalMachine {

enum DataType {
    ANALOG,
    DIGITAL,
    default = ANALOG
};

class SchemaUtils { //  Acts like an interface

    public:

        Information DecompressInfo(void * encryptedInfo);

        void * DecryptInfo(void * encryptedInfo);

        void * EncryptCompressedData(void * compressetInfo);

        void * CompressData(MsgInfo data);

        bool SaveData(void * data);

        bool SaveData(MsgInfo data);

};

}
