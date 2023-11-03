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
#include <cstdint>
#include <AnalogData.hh>
#include <DigitalData.hh>

// Base class for information

namespace Information {

constexpr std::string_view DEFAULT_ADDRESS {"UNDEFINED_ADDRESS"};
constexpr std::string_view DEFAULT_ID {"0"};
constexpr std::string_view DEFAULT_VALUE {"1"};
constexpr std::string_view DEFAULT_TIME {"2000/01/01 00:00:00"};
constexpr std::string_view TIME_FORMAT {"%Y/%m/%d %H:%M:%S"};
constexpr std::string_view DEFAULT_QUALITY {"0"};

enum DataType {
    UNKNOWN,
    ANALOG,
    DIGITAL
};

class Information {
 
    public:
   
        Information();
        Information(std::string id, std::string value, std::string timestamp, std::string a_quality, int32_t dataType);
        Information(c::Analog analogInstance);
        Information(c::Digital digitalInstance);
        ~Information();

        bool empty();

        std::string GetInfoId();
        std::string GetInfoValue();
        std::string GetInfoTimeStamp();
        std::string GetInfoQuality();
        int32_t GetDataType();

        std::string toString();

        void SetInfoId(std::string input) { a_infoId  = input;}
        void SetInfoValue(std::string input) { a_data  = input;}
        void SetInfoTimeStamp(std::string input) { a_timeStamp  = input;}
        void SetInfoQuality(std::string input) { a_quality = input;}

        bool operator==(Information& other);

    protected:

        std::string a_data;

        std::string a_infoId;

        std::string a_timeStamp;

        std::string a_quality;

        int32_t a_DataType;
};

};