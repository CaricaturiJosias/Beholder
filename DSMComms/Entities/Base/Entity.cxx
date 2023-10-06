/**
 * @file Entity.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Entity.hxx"
// For DEFAULT_ID and DEFAULT_ADDRESS
#include <Information.hxx>

namespace Entity {


    Entity& Entity::operator=(const Entity& other) {
        entityAddress = other.entityAddress;
        entityId = other.entityId;
        entityType = other.entityType;
        return *this;
    }

    Entity::Entity() {
        entityAddress = Information::DEFAULT_ADDRESS;
        entityId = Information::DEFAULT_ID;
        entityType = UNKNOWN;
    }

    Entity::Entity(std::string id, std::string address, ENTITY_TYPE type) {
        entityAddress = id;
        entityId = address;
        entityType = type;
    }

    Entity::~Entity() {
        // TODO
    }

    std::string Entity::getEntityId(){
        return entityId;
    }

    void Entity::setEntityId(std::string newId) {
        entityId = newId;
    }

    std::string Entity::getEntityAddress(){
        return entityAddress;
    }

    void Entity::setEntityAddress(std::string newAddress) {
        entityAddress = newAddress;
    }

    ENTITY_TYPE Entity::getEntityType() {
        return entityType;
    }
};