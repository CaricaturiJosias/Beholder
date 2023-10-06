/**
 * @file BaseMsg.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>

#include <Entity.hxx>
#include <Information.hxx>

namespace Message {

    class BaseMsg {

        public:

            BaseMsg();

            ~BaseMsg();
            
            BaseMsg(Information::Information info, Entity::Entity sender);

            Information::Information getMessageInfo() { return messageInfo; }

            Entity::Entity getMessageSender() { return messageSender; }

            std::string getMessageTimestamp() { return timestamp; }

        protected:

            static Information::Information messageInfo;

            static Entity::Entity messageSender;

            static std::string timestamp;
    };

};