/**
 * @file MsgProcessor.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../DataModels/MsgInfo/MsgInfo.hpp"
#include "../../DataModels/Msg/SOAPMsg.hpp"
#include "../Actors/Sender.hpp"

#include <string.h>
#include <vector>

namespace SOA {

class MsgProcessor {

    public:

        bool ValidateMessage(MsgInfo data);

        bool IsSenderKnown(SOAPMsg message);

        bool ProcessMsg(SOAPMsg message);

        bool ProcessMsg(MsgInfo message);

        void ReturnToSender(Sender sender, MsgInfo message);

        MsgInfo GetCommandInfo(std::string command);

        std::vector<std::string> GetCommandInfo(SOAPMsg message);
};

};