#include <gtest/gtest.h>

#include <Beholder/AnalogData.hh>
#include <Beholder/DigitalData.hh>

#include <Beholder/MachineUtils.hxx>
#include <Beholder/SchemaUtils.hxx>

#include <filesystem>
#include <fstream>

// Apache Avro related imports
#include <avro/ValidSchema.hh>
#include <avro/Compiler.hh>
#include <avro/Decoder.hh>
#include <avro/Encoder.hh>
#include <avro/DataFile.hh>
#include "avro/Generic.hh"

TEST(AvroTest, TestAnalog) {

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

    std::filesystem::path schemaPath = LocalMachine::SchemaUtils::GetSchema(LocalMachine::ANALOG);
    std::ifstream schemaStream(schemaPath);

    avro::ValidSchema schemaResult;
    avro::compileJsonSchema(schemaStream, schemaResult);
    
    std::string tempFile = "./AvroTest/TEST_ANALOG.tmp";

    avro::DataFileWriter<c::Analog>
            writerInstance(
                tempFile.c_str(),
                schemaResult);
    writerInstance.write(analogInstance);
    writerInstance.close();

    ASSERT_EQ(std::filesystem::exists(tempFile), true);

    avro::DataFileReader<c::Analog> readerInstance(tempFile.c_str(), schemaResult);
    c::Analog analog;

    readerInstance.read(analog);

    readerInstance.close();
    ASSERT_EQ(analog.id, id);
    ASSERT_EQ(std::to_string(analog.value), value);
    ASSERT_EQ(std::to_string(analog.quality), quality);
    ASSERT_EQ(analog.timestamp, timestamp);
    
    std::filesystem::remove(tempFile);
}

TEST(AvroTest, TestDigital) {

    // Prepare
    std::string id = "TESTING_ID";
    std::string value = "3";
    std::string timestamp = "2000/01/01 00:00:00";
    std::string quality = "9";
    int32_t dataType = LocalMachine::DIGITAL;
    
    c::Digital digitalInstance;
    digitalInstance.id = id;
    digitalInstance.value = std::stoi(value);
    digitalInstance.quality = std::stoi(quality);
    digitalInstance.timestamp = timestamp;

    std::filesystem::path schemaPath = LocalMachine::SchemaUtils::GetSchema(LocalMachine::DIGITAL);
    std::ifstream schemaStream(schemaPath);

    avro::ValidSchema schemaResult;
    avro::compileJsonSchema(schemaStream, schemaResult);
    
    std::string tempFile = "./AvroTest/TEST_DIGITAL.tmp";

    avro::DataFileWriter<c::Digital>
            writerInstance(
                tempFile.c_str(),
                schemaResult);
    writerInstance.write(digitalInstance);
    writerInstance.close();

    ASSERT_EQ(std::filesystem::exists(tempFile), true);

    avro::DataFileReader<c::Digital> readerInstance(tempFile.c_str(), schemaResult);
    c::Digital digital;

    readerInstance.read(digital);

    readerInstance.close();
    ASSERT_EQ(digital.id, id);
    ASSERT_EQ(std::to_string(digital.value), value);
    ASSERT_EQ(std::to_string(digital.quality), quality);
    ASSERT_EQ(digital.timestamp, timestamp);
    
    std::filesystem::remove(tempFile);
}