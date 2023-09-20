/**
 * @file AvrosHelper.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief Contains methods regarding the virtual table of a machine and its stored data
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "AvrosHelper.hxx"

namespace LocalMachine {

AvrosHelper::AvrosHelper() {
    // TODO
}

AvrosHelper::~AvrosHelper() {
    // TODO
}

keyMap AvrosHelper::GetKeyMap() {
    // TODO
}

valueMap AvrosHelper::GetValueMap() {
    // TODO
}

Value * AvrosHelper::GetStoredValue(storageId id) {
    // TODO
}

double AvrosHelper::numRows = 0;

keyMap AvrosHelper::dataMapKey = keyMap();
valueMap AvrosHelper::dataMapValue = valueMap();

AvrosHelper * AvrosHelper::table = nullptr;

} // Namespace LocalMachine