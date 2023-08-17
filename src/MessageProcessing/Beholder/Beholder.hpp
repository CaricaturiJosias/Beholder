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

#include "../../DataModels/MsgInfo/MsgInfo.hpp"
#include "../../LocalHelpers/MachineUtils/MachineUtils.hpp"

class Beholder {

    // Should look for surrounding beholder on the start
    void UpdateOtherTables(MsgInfo updateData);

    void LogEventAll(std::string msg, LocalMachine::EventType event);

};