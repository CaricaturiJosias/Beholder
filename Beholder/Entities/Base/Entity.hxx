/**
 * @file Entity.hxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string>
#include <vector>

namespace Entity {

    using ENTITY_TYPE = enum entities {
            DATA_SOURCE, // Can only provide
            DATA_CONSUMER, // Can only request data
            DATA_EDITOR, // Can request and edit data
            DATA_SHAREHOLDER, // Can provide, request and edit data
            BEHOLDER, // DSMComms entity, we store its IOR name here
            UNKNOWN
        };

    class Entity {
        
        public:
            
            Entity();
            
            /**
             * @brief Constructor for an entity
             * 
             * @param[in] id Defines the given name of an Entity, might be an arbitraty number or whatever
             * @param[in] address Acts like a form of accessing the Entity (The restfull api page or an ip address or a CORBA IOR name)
             * @param[in] type Entity type that defines the role of the entity, might be both
            */
            Entity(std::string id, std::string address, ENTITY_TYPE type);

            ~Entity();

            std::string getEntityId();
            void setEntityId(std::string newId);

            std::string getEntityAddress();
            void setEntityAddress(std::string newAddress);

            ENTITY_TYPE getEntityType();
            void setEntityType(ENTITY_TYPE newId);

            Entity& operator=(const Entity& other);
            bool operator==(Entity& other);

        protected:

            // Logging + Identification
            std::string entityId;

            // Necessary to send a message (Ip:port or https://RESTAccess.com)
            std::string entityAddress;

            ENTITY_TYPE entityType;
            
    };


};