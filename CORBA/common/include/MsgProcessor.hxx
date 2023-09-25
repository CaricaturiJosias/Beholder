/**
 * @file MsgProcessor.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <BaseMsg.hxx>
#include <SOAPMsg.hxx>
#include <Entity.hxx>

#include <string>
#include <vector>

namespace SOA {

class MsgProcessor {

    public:

        bool ValidateMessage(Message::BaseMsg data);

        bool IsSenderKnown(Message::BaseMsg message);

        bool ProcessMsg(Message::BaseMsg message);

        bool ProcessMsg(Message::SOAPMsg message);

        void ReturnToSender(Entity::Entity sender, Message::BaseMsg message);

        Message::BaseMsg GetCommandInfo(std::string command);

        std::vector<std::string> GetCommandInfo(Message::BaseMsg message);
};

};