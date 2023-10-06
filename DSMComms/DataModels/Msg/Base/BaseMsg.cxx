/**
 * @file BaseMsg.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "BaseMsg.hxx"
#include <MachineUtils.hxx>

namespace Message {

    Information::Information BaseMsg::messageInfo = {};

    Entity::Entity BaseMsg::messageSender = {};

    std::string BaseMsg::timestamp = std::string(Information::DEFAULT_TIME);
            
    BaseMsg::BaseMsg() {
        // TODO
    }

    BaseMsg::BaseMsg(Information::Information info, Entity::Entity sender) {
        messageInfo = info;
        messageSender = sender;
        timestamp = LocalMachine::MachineUtils::GetCurrentTime();
    }

    BaseMsg::~BaseMsg() {
        // TODO
    }

};