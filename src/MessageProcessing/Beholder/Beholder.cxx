/**
 * @file Beholder.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Beholder.hxx"

std::unique_ptr<LocalMachine::VirtualTable> Beholder::s_virtualTable = nullptr;

Beholder::Beholder() {
    s_virtualTable.reset(new LocalMachine::VirtualTable());
}

Beholder::~Beholder() {
    s_virtualTable.reset(nullptr); // Effectivelly deletes the pointer
}

void Beholder::UpdateOtherTables(MsgInfo updateData) {
    // Not implemented now
}

void Beholder::LogEventAll(std::string msg, LocalMachine::EventType event) {
    // Not implemented now
}
