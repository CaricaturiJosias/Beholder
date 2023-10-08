/**
 * @file EntityManager.hxx
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

#include <Entity.hxx>

namespace Entity {

using ENTITY_LIST = std::vector<Entity *>;

    // Base class

    /**
     * Class that holds Entity Instances in it
     * 
     * - The EntityManager owns the data it holds (The Entity instances)
    */
    class EntityManager {
        
        public:
            
            EntityManager();

            ~EntityManager();

            bool registerEntity(std::string id, std::string address, ENTITY_TYPE type);

            bool removeEntity(Entity * entityToRemove);
            
            Entity * getEntity(std::string entityId);

        protected:

            // Will make an Id
            unsigned long entityCount;

            // Definition on how to track all Entities sendind information
            ENTITY_LIST entityList;

    };


};