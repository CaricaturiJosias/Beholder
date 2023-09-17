/**
 * @file Info.hxx
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

class Info {
    
    public:
        
        Info();
        virtual ~Info();

        virtual std::string getInfoId();
        virtual std::string getInfoValue();

    protected:

        std::string s_ptr_data;

        std::string s_infoId;
};

};