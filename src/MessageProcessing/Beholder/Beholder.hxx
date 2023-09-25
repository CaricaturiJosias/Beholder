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

#include <BaseMsg.hxx>
#include <MachineUtils.hxx>
#include <VirtualTable.hxx>
#include <memory>

class Beholder {

    public:
        Beholder();
        ~Beholder();

        // Should look for surrounding beholder on the start
        void UpdateOtherTables(Message::BaseMsg updateData);

        void LogEventAll(std::string msg, LocalMachine::EventType event);

    private:

        static std::unique_ptr<LocalMachine::VirtualTable> s_virtualTable;
};