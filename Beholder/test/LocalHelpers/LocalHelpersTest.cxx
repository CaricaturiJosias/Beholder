#include <gtest/gtest.h>

#include <Beholder/SchemaUtils.hxx>
#include <Beholder/VirtualTable.hxx>
#include <Beholder/MachineUtils.hxx>
#include <Beholder/Information.hxx>
#include <Beholder/BaseMsg.hxx>


TEST(VirtualTable, GetInstance) {
    std::shared_ptr<LocalMachine::VirtualTable> table = LocalMachine::VirtualTable::GetInstance();
    ASSERT_NE(table, nullptr);
}

TEST(VirtualTable, GetBuffer) {
    // Prepare
    std::shared_ptr<LocalMachine::VirtualTable> table = LocalMachine::VirtualTable::GetInstance();

    // Act
    LocalMachine::BUFFER_MAP * buffer = table->getBuffer();

    // Expected results
    ASSERT_EQ(buffer[LocalMachine::ANALOG].size(), 0);
    ASSERT_EQ(buffer[LocalMachine::DIGITAL].size(), 0);
}

TEST(VirtualTable, StoreValue) {
    // Prepare
    std::shared_ptr<LocalMachine::VirtualTable> table = LocalMachine::VirtualTable::GetInstance();
    std::string id = "TEST_ID";
    std::string value = "1.1";
    std::string timestamp = "2012/02/23 05:12:22";
    std::string quality = "1";
    int32_t dataType = LocalMachine::ANALOG;
    Information::Information * info = new Information::Information(id, value, timestamp, quality, dataType);
    // Act
    std::string path;
    // Make sure it is stored in the buffer
    for (int i = 0; i < LocalMachine::MAX_BUFFER_SIZE; ++i) {
         path = LocalMachine::SchemaUtils::CompressData(info);
    }

    // Check
    // Path not empty
    ASSERT_NE(path, "");

    // It will always be a single value
    std::vector<Information::Information> listOfInfos = LocalMachine::MachineUtils::LookUpData(id, timestamp);
    ASSERT_EQ(listOfInfos.size(), 1);

    std::vector<Information::Information>::iterator instance = listOfInfos.begin();
    ASSERT_EQ(instance->GetInfoId(), id);
    ASSERT_EQ(instance->GetInfoValue(), "1.100000"); // 1.1 is saved with 6 decimal digits
    ASSERT_EQ(instance->GetInfoTimeStamp(), timestamp);
    ASSERT_EQ(instance->GetInfoQuality(), quality);
    ASSERT_EQ(instance->GetDataType(), dataType);

}

TEST(VirtualTable, Encryption) {
    // WORK TODO
    ASSERT_EQ(LocalMachine::SchemaUtils::EncryptCompressedData(nullptr), nullptr);
}

TEST(VirtualTable, SaveWithMsg) {   
    // WORK TODO
    Message::BaseMsg msg {};
    Information::Information info {};
    ASSERT_EQ(LocalMachine::SchemaUtils::SaveData(msg, info), true);
}

TEST(VirtualTable, SchemaTest) {   
    // WORK TODO
    ASSERT_NE(LocalMachine::SchemaUtils::GetSchema(Information::ANALOG), "");
}
