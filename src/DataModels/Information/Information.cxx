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

#pragma once

#include "Information.hxx"

namespace Information {

Information::Information() {
    a_data = std::string(DEFAULT_VALUE);
    a_infoId = std::string(DEFAULT_ID);
    a_timeStamp = std::string(DEFAULT_TIME);
    a_DataType = UNKNOWN;
}

Information::Information(std::string id, std::string value, std::string timestamp, DataType dataType) {
    a_infoId = id;
    a_data = value;
    a_timeStamp = timestamp;
    a_DataType = dataType;
}

Information::~Information() {
    // Nothing for now
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

DataType Information::GetDataType() {
    return a_DataType;
}

};