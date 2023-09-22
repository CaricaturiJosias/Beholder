/**
 * @file Information.hxx
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

// Base class for information

namespace Information {

constexpr std::string_view DEFAULT_ADDRESS {"UNDEFINED_ADDRESS"};
constexpr std::string_view DEFAULT_ID {"UNDEFINED_ID"};
constexpr std::string_view DEFAULT_VALUE {"UNDEFINED_VALUE"};
constexpr std::string_view DEFAULT_TIME {"2000-01-01 00:00:00"};
constexpr std::string_view TIME_FORMAT {"%Y-%m-%d %H:%M:%S"};

enum DataType {
    ANALOG,
    DIGITAL,
    UNKNOWN
};

class Information {
    
    public:
        
        Information();
        Information(std::string id, std::string value, std::string timestamp, DataType dataType);
        ~Information();

        std::string GetInfoId();
        std::string GetInfoValue();
        std::string GetInfoTimeStamp();
        DataType GetDataType();

    protected:

        std::string a_data;

        std::string a_infoId;

        std::string a_timeStamp;

        DataType a_DataType;
};

};