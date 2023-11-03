/**
 * @file SOAPMsg.h
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

namespace Message {

    class SOAPMsg : public BaseMsg {

        public:
        
            SOAPMsg();

            SOAPMsg(Information::Information info, Entity::Entity sender) : BaseMsg(info, sender) {}
            
            ~SOAPMsg();
    };

};