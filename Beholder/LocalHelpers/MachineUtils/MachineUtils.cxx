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
#include <Machine.hxx>

namespace LocalMachine {

    // Default value for error throwing
    DataType MachineUtils::typeMap{
        std::make_pair(UNKNOWN, std::string(UNKNOWN_TYPE)),
        std::make_pair(ANALOG, std::string(ANALOG_TYPE)),
        std::make_pair(DIGITAL, std::string(DIGITAL_TYPE))   
    };
    
    bool MachineUtils::CheckPermission(std::string command, Entity::Entity sender) {
        return true;
    }

    double MachineUtils::GetRecordsAmmount() {
        return 0;
    }

    bool MachineUtils::hasSpace(void * encryptedData) {
        return true;
    }

    void MachineUtils::LogEvent(std::string msg, EventType eventType) {
        return;
    }

    bool MachineUtils::SaveData(void * data) {
        return true;
    }

    bool MachineUtils::SaveData(Message::BaseMsg data) {
        return true;
    }

    void MachineUtils::UpdateTable(std::vector<Information::Information> information, Entity::Entity dataOwner) {
        return;
    }

    std::vector<Information::Information> MachineUtils::LookUpData(std::string id, std::string timestamp) {
        // We don't expect it to be empty
        std::shared_ptr<VirtualTable> table = Machine::GetVirtualTable();
        return table->GetStoredValue(id, timestamp);
    }

    std::vector<Information::Information> MachineUtils::GetDataInArray(Message::BaseMsg dataInfo) {
        return std::vector<Information::Information>{};
    }

    std::string MachineUtils::GetCurrentTime() {
        // Get time in the following format
        time_t currentTime;
        time(&currentTime);
        struct tm* timeInfo = localtime(&currentTime);

        char timeString[50];
        strftime(timeString, sizeof(timeString), std::string(Information::TIME_FORMAT).c_str(), timeInfo);
        return std::string(timeString);
    }

    std::string MachineUtils::GetType(int32_t typeValue) {
        DataType::iterator it = typeMap.find(typeValue);
        if (it == typeMap.end()) {
            // TODO - Log error
            return typeMap[UNKNOWN];
        }
        return it->second;
    }

};
