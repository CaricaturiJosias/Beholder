/**
 * @file GenericMsg.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <BaseMsg.hxx>

namespace Message {

    class GenericMsg : public BaseMsg {

        public:
        
            GenericMsg();

            GenericMsg(Information::Information info, Entity::Entity sender) : BaseMsg(info, sender) {}
            
            ~GenericMsg();
    };

};