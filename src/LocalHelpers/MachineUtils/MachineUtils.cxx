/**
 * @file MachineUtils.cxx
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "MachineUtils.hxx"

namespace LocalMachine {

    enum EventType {
        Something // TODO
    };
   
    bool MachineUtils::CheckPermission(std::string command, Entity::Entity sender) {

    }

    Information::Information MachineUtils::DecompressInfo(void * encryptedInfo) {

    }

    void * MachineUtils::DecryptInfo(void * encryptedInfo) {

    }

    void * MachineUtils::EncryptCompressedData(void * compressetInfo) {

    }

    void * MachineUtils::CompressData(Message::BaseMsg data) {

    }

    double MachineUtils::GetRecordsAmmount() {

    }

    bool MachineUtils::DataLookUp(Message::BaseMsg data) {

    }

    bool MachineUtils::hasSpace(void * encryptedData) {

    }

    void MachineUtils::LogEvent(std::string msg, EventType eventType) {

    }

    bool MachineUtils::SaveData(void * data) {

    }

    bool MachineUtils::SaveData(Message::BaseMsg data) {

    }

    void MachineUtils::UpdateTable(void * data, double dataOwner) {

    }

    Information::Information MachineUtils::LookUpData(Message::BaseMsg data) {

    }

    VirtualTable MachineUtils::GetVirtualTable() {

    }

    std::vector<Information::Information> MachineUtils::GetDataInArray(Message::BaseMsg dataInfo) {

    }

    std::string MachineUtils::GetCurrentTime() {
        // Get time in the following format
        time_t currentTime;
        time(&currentTime);
        struct tm* timeInfo = localtime(&currentTime);

        char timeString[50];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);
        return std::string(timeString);
    }

    // Doest belong to the class because contains template
    template<typename Number>
    bool IsStringType(std::string& value) {
        Number n;
        std::string::iterator it = value.begin();
        return((std::istringstream(value) >> n >> std::ws).eof());
    }

}
