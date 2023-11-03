#include <gtest/gtest.h>

#include <Beholder/BaseMsg.hxx>
#include <Beholder/GenericMsg.hxx>
#include <Beholder/SOAPMsg.hxx>

#include <Beholder/Information.hxx>
#include <Beholder/Entity.hxx>

TEST(MsgTest, BaseMsgCreation) {

    Information::Information test{};
    Entity::Entity entity{};

    Message::BaseMsg * testMsg = new Message::BaseMsg(test, entity);

    ASSERT_EQ(testMsg->getMessageInfo() == test, true);
    ASSERT_EQ(testMsg->getMessageSender() == entity, true);
    
    delete testMsg;
}

TEST(MsgTest, GenericMsgCreation) {

    Information::Information test{};
    Entity::Entity entity{};

    Message::GenericMsg * testMsg = new Message::GenericMsg(test, entity);

    ASSERT_EQ(testMsg->getMessageInfo() == test, true);
    ASSERT_EQ(testMsg->getMessageSender() == entity, true);
    
    delete testMsg;
}

TEST(MsgTest, SOAPMsgCreation) {

    Information::Information test{};
    Entity::Entity entity{};

    Message::SOAPMsg * testMsg = new Message::SOAPMsg(test, entity);

    ASSERT_EQ(testMsg->getMessageInfo() == test, true);
    ASSERT_EQ(testMsg->getMessageSender() == entity, true);
    
    delete testMsg;
}