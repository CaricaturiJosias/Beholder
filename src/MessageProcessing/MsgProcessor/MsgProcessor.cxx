/**
 * @file MsgProcessor.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "MsgProcessor.hxx"

namespace SOA {

    bool MsgProcessor::ValidateMessage(Message::BaseMsg data) {
        return true;
    }

    bool MsgProcessor::IsSenderKnown(Message::BaseMsg message) {
        return true;
    }

    bool MsgProcessor::ProcessMsg(Message::BaseMsg message) {
        return true;
    }

    bool MsgProcessor::ProcessMsg(Message::SOAPMsg message) {
        return true;
    }

    void MsgProcessor::ReturnToSender(Entity::Entity sender, Message::BaseMsg message) {
        // TODO
    }

    Message::BaseMsg MsgProcessor::GetCommandInfo(std::string command) {
        Message::BaseMsg lmao;
        return lmao;
    }

    std::vector<std::string> GetCommandInfo(Message::SOAPMsg message) {
        std::vector<std::string> temporario;
        return temporario;
    }

};