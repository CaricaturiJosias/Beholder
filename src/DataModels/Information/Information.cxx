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
    a_ptr_data = std::string(DEFAULT_VALUE);
    a_infoId = std::string(DEFAULT_ID);
    a_timeStamp = std::string(DEFAULT_TIME);
}



};