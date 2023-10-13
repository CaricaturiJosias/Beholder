/**
 * @file Information.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Information.hxx"
#include <MachineUtils.hxx> // For dataType constants

namespace Information {

Information::Information() {
    a_data = std::string(DEFAULT_VALUE);
    a_infoId = std::string(DEFAULT_ID);
    a_timeStamp = std::string(DEFAULT_TIME);
    a_quality = std::string(DEFAULT_QUALITY);
    a_DataType = 0;
}

Information::Information(std::string id, std::string value, std::string timestamp, std::string quality, int32_t dataType) {
    a_infoId = id;
    a_data = value;
    a_timeStamp = timestamp;
    a_quality = quality;
    a_DataType = dataType;
}

Information::Information(c::Analog analogInstance){
    a_infoId = std::to_string(analogInstance.id);
    a_data = std::to_string(analogInstance.value);
    a_quality = std::to_string(analogInstance.quality);
    a_timeStamp = analogInstance.timestamp;
    a_DataType = LocalMachine::ANALOG;
}

Information::Information(c::Digital digitalInstance) {
    a_infoId = std::to_string(digitalInstance.id);
    a_data = std::to_string(digitalInstance.value);
    a_quality = std::to_string(digitalInstance.quality);
    a_timeStamp = digitalInstance.timestamp;
    a_DataType = LocalMachine::DIGITAL;
}

Information::~Information() {
    // Nothing for now
}

bool Information::empty() {
    return (a_data == std::string(DEFAULT_VALUE) &&
            a_infoId == std::string(DEFAULT_ID) &&
            a_timeStamp == std::string(DEFAULT_TIME) &&
            a_quality == std::string(DEFAULT_QUALITY) &&
            a_DataType == 0);
}

std::string Information::GetInfoId() {
    return a_infoId;
}

std::string Information::GetInfoValue() {
    return a_data;
}

std::string Information::GetInfoTimeStamp() {
    return a_timeStamp;
}

std::string Information::GetInfoQuality() {
    return a_quality;
}

int32_t Information::GetDataType() {
    return a_DataType;
}

};