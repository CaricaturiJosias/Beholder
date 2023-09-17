/**
 * @file MsgProcessor.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "MsgProcessor.hxx"

namespace SOA {

    bool ValidateMessage(MsgInfo data) {
        return true;
    }

    bool IsSenderKnown(SOAPMsg message) {
        return true;
    }

    bool ProcessMsg(SOAPMsg message) {
        return true;
    }

    bool ProcessMsg(MsgInfo message) {
        return true;
    }

    void ReturnToSender(Sender sender, MsgInfo message) {
        
    }

    MsgInfo GetCommandInfo(std::string command) {
        MsgInfo lmao;
        return lmao;
    }

    std::vector<std::string> GetCommandInfo(SOAPMsg message) {
        std::vector<std::string> temporario;
        return temporario;
    }

};