/**
 * @file Info.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "Info.hxx"

namespace Information {

Info::Info() {
    s_ptr_data = std::string(DEFAULT_VALUE);
    s_infoId = std::string(DEFAULT_ID);
}



};