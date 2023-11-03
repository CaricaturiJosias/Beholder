/**
 * @file EntityManager.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>

#include "EntityManager.hxx"
// For DEFAULT_ID and DEFAULT_ADDRESS
#include <Information.hxx>

namespace Entity {

    EntityManager::EntityManager() {
        entityList = ENTITY_LIST();
        entityCount = 0;
    }

    EntityManager::~EntityManager() {
        ENTITY_LIST::iterator it;
        for (auto& entity : entityList) {
            delete entity;
        }
        entityList.clear();
        entityCount = 0;
    }

    bool EntityManager::registerEntity(std::string id, std::string address, ENTITY_TYPE type){
        // TODO - Develop logging
        Entity * newEntity = new Entity(id, address, type);

        if (newEntity == nullptr) {
            // Something is really wrong if this is called?
            return false;
        } else if (newEntity->getEntityAddress() == Information::DEFAULT_ADDRESS ||
                   newEntity->getEntityId() == Information::DEFAULT_ID ||
                   newEntity->getEntityType() == UNKNOWN) {
            return false;
        }

        entityList.push_back(newEntity);
        entityCount++;
        return true;
    }

    bool EntityManager::removeEntity(Entity * entityToRemove) {
        // TODO - Develop logging
        if (entityToRemove == nullptr) {
            return false;
        } else if (entityCount == 0 || entityList.empty()) {
            return false;
        }

        ENTITY_LIST::iterator it = std::find(entityList.begin(), entityList.end(), entityToRemove);

        entityList.erase(it);

        // Scenario 1: More than 1 item, after removal new item is returned
        // Scenario 2: Only 1 item, after removal list is empty and it is entityList.end()
        if (it == entityList.end() || // Scenario 1
                entityList.empty()) {// Scenario 2
            --entityCount;
            return true;
        }
        // Something went wrong
        return false;
    }

    Entity * EntityManager::getEntity(std::string entityId) {
        // TODO - Develop logging
        if (entityList.empty() || entityCount == 0) {
            return nullptr;
        }

        for (auto& entity : entityList) {
            if (entity->getEntityId() == entityId){
                return entity;
            }
        }
        return nullptr;
    }

};