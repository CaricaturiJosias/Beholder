#include <gtest/gtest.h>

#include <Beholder/Information.hxx>
#include <Beholder/MachineUtils.hxx>

TEST(InformationTest, createInfoEmpty) {
    // Test empty constructor
    
    // Act
    Information::Information * test = new Information::Information();

    // Check expected results
    
    ASSERT_EQ(test->empty(), true);
    ASSERT_EQ(test->GetInfoId(), Information::DEFAULT_ID);
    ASSERT_EQ(test->GetInfoValue(), Information::DEFAULT_VALUE);
    ASSERT_EQ(test->GetInfoTimeStamp(), Information::DEFAULT_TIME);
    ASSERT_EQ(test->GetInfoQuality(), Information::DEFAULT_QUALITY);
    ASSERT_EQ(test->GetDataType(), LocalMachine::UNKNOWN);

    delete test;
}

TEST(InformationTest, createInfoWithValues) {
    // Test value constructor
    
    // Prepare
    std::string id = "TESTING_ID";
    std::string value = "1.111";
    std::string timestamp = "2000/01/01 00:00:00";
    std::string quality = "9";
    int32_t dataType = LocalMachine::ANALOG;

    // Act
    Information::Information * test = new Information::Information(id, value, timestamp, quality, dataType);  

    // Check expected results
    ASSERT_EQ(test->GetInfoId(), id);
    ASSERT_EQ(test->GetInfoValue(), value);
    ASSERT_EQ(test->GetInfoTimeStamp(), timestamp);
    ASSERT_EQ(test->GetInfoQuality(), quality);
    ASSERT_EQ(test->GetDataType(), dataType);
    
}

TEST(InformationTest, createInfoWithAnalog) {
    // Test value constructor
    
    // Prepare
    std::string id = "TESTING_ID";
    std::string value = "1.111000";
    std::string timestamp = "2000/01/01 00:00:00";
    std::string quality = "9";
    int32_t dataType = LocalMachine::ANALOG;
    
    c::Analog analogInstance;
    analogInstance.id = id;
    analogInstance.value = std::stod(value);
    analogInstance.quality = std::stoi(quality);
    analogInstance.timestamp = timestamp;

    // Act
    Information::Information * test = new Information::Information(analogInstance);  

    // Check expected results
    ASSERT_EQ(test->GetInfoId(), id);
    ASSERT_EQ(test->GetInfoValue(), value);
    ASSERT_EQ(test->GetInfoTimeStamp(), timestamp);
    ASSERT_EQ(test->GetInfoQuality(), quality);
    delete test;
}

TEST(InformationTest, createInfoWithDigital) {
    // Test value constructor
    
    // Prepare
    std::string id = "TESTING_ID";
    std::string value = "1";
    std::string timestamp = "2000/01/01 00:00:00";
    std::string quality = "9";
    int32_t dataType = LocalMachine::DIGITAL;
    
    c::Digital digitalInstance;
    digitalInstance.id = id;
    digitalInstance.value = std::stod(value);
    digitalInstance.quality = std::stoi(quality);
    digitalInstance.timestamp = timestamp;

    // Act
    Information::Information * test = new Information::Information(digitalInstance);  

    // Check expected results
    ASSERT_EQ(test->GetInfoId(), id);
    ASSERT_EQ(test->GetInfoValue(), value);
    ASSERT_EQ(test->GetInfoTimeStamp(), timestamp);
    ASSERT_EQ(test->GetInfoQuality(), quality);

    delete test;
}