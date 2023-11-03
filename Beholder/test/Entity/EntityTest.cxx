#include <gtest/gtest.h>

#include <Beholder/Entity.hxx>
#include <Beholder/Information.hxx>
#include <Beholder/EntityManager.hxx>

TEST(EntityTest, EmptyInstance) {
    Entity::Entity * entity = new Entity::Entity();
    ASSERT_EQ(entity->getEntityAddress(), Information::DEFAULT_ADDRESS);
    ASSERT_EQ(entity->getEntityId(), Information::DEFAULT_ID);
    ASSERT_EQ(entity->getEntityType(), Entity::ENTITY_TYPE::UNKNOWN);
}

TEST(EntityTest, NormalInstance) {
    std::string testId = "TESTING_ID";
    std::string testAddress = "TESTING_ADDRESS";
    Entity::ENTITY_TYPE testType = Entity::ENTITY_TYPE::DATA_CONSUMER;
    Entity::Entity * entity = new Entity::Entity(testId, testAddress, testType);

    ASSERT_EQ(entity->getEntityId(), testId);
    ASSERT_EQ(entity->getEntityAddress(), testAddress);
    ASSERT_EQ(entity->getEntityType(), testType);
}

TEST(EntityTest, InstanceChange) {
    std::string testId = "TESTING_ID";
    std::string testAddress = "TESTING_ADDRESS";
    Entity::ENTITY_TYPE testType = Entity::ENTITY_TYPE::DATA_CONSUMER;
    
    Entity::Entity * entity = new Entity::Entity();

    ASSERT_EQ(entity->getEntityAddress(), Information::DEFAULT_ADDRESS);
    ASSERT_EQ(entity->getEntityId(), Information::DEFAULT_ID);
    ASSERT_EQ(entity->getEntityType(), Entity::ENTITY_TYPE::UNKNOWN);

    entity->setEntityAddress(testAddress);
    entity->setEntityId(testId);

    ASSERT_EQ(entity->getEntityAddress(), testAddress);
    ASSERT_EQ(entity->getEntityId(), testId);

    // Test copy constructor
    Entity::Entity * newEntity = entity;

    ASSERT_EQ(newEntity->getEntityAddress(), testAddress);
    ASSERT_EQ(newEntity->getEntityId(), testId);
}


TEST(EntityTest, CreateManager) {


    Entity::EntityManager * manager = new Entity::EntityManager();

    ASSERT_EQ(manager->getEntity("None"), nullptr);

    std::string testId = "TESTING_ID";
    std::string testAddress = "TESTING_ADDRESS";
    Entity::ENTITY_TYPE testType = Entity::ENTITY_TYPE::DATA_CONSUMER;


    for (int i = 0; i < 5; ++i) {
        std::string testId = "TESTING_ID_" + std::to_string(i);
        ASSERT_EQ(manager->registerEntity(testId, testAddress, testType), true);
    }

    for (int i = 0; i < 5; ++i) {
        std::string testId = "TESTING_ID_" + std::to_string(i);
        ASSERT_NE(manager->getEntity(testId), nullptr);
    }

    std::string testRemoveId = "TESTING_ID_0";
    Entity::Entity * toRemoveEntity = new Entity::Entity(testRemoveId, testAddress, testType);
    Entity::Entity * entity = new Entity::Entity();

    // Test successfull removal of the entity
    ASSERT_EQ(manager->removeEntity(toRemoveEntity), true);

    // Look to see if we can find the entity after removal
    bool found = false;
    for (int i = 0; i < 5; ++i) {
        std::string testId = "TESTING_ID_" + std::to_string(i);
        entity = manager->getEntity(testId);
        if (entity == nullptr) continue;
        found |= (entity->getEntityId() == testRemoveId);
    }

    ASSERT_EQ(found, false);
}