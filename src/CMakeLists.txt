# CMakeLists.txt in src/ (Main CMakeLists.txt)

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Beholder)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set (LIB_PATH "/usr/lib/beholder/")
set (INC_PATH "/usr/include/beholder/")

# # Check if the folder exists
# if(NOT EXISTS "${LIB_PATH}")
#     # Create the folder if it doesn't exist
#     file(MAKE_DIRECTORY "${LIB_PATH}")
# endif()

# if(NOT EXISTS "${INC_PATH}")
#     # Create the folder if it doesn't exist
#     file(MAKE_DIRECTORY "${INC_PATH}")
# endif()

set(LIB_DIRS
    DataModels
    Entities
    3PP
    MessageProcessing
    LocalHelpers        
)

# To make simplified include
set (SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories( PUBLIC
    ${SRC_DIR}/3PP/Pugi
    ${SRC_DIR}/DataModels/Information
    ${SRC_DIR}/DataModels/Msg
    ${SRC_DIR}/DataModels/Msg/Base
    ${SRC_DIR}/Entities
    ${SRC_DIR}/Entities/Base
    ${SRC_DIR}/LocalHelpers/SchemaHelpers/GeneratedHeaders
    ${SRC_DIR}/LocalHelpers/MachineUtils
    ${SRC_DIR}/LocalHelpers/VirtualTable
    ${SRC_DIR}/MessageProcessing/Beholder
    ${SRC_DIR}/MessageProcessing/MsgProcessor
    # Add other include directories as needed
)

# HARDCODED BECAUSE CMAKE DOES NOT LIKE IT WHEN I TRY TO DO STUFF
set (MAIN_SOURCES
    ${SRC_DIR}/3PP/Pugi/pugixml.cpp
    ${SRC_DIR}/DataModels/Information/Information.cxx
    ${SRC_DIR}/DataModels/Msg/Base/BaseMsg.cxx
    ${SRC_DIR}/DataModels/Msg/GenericMsg.cxx
    ${SRC_DIR}/DataModels/Msg/SOAPMsg.cxx
    ${SRC_DIR}/Entities/EntityManager.cxx
    ${SRC_DIR}/Entities/Base/Entity.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/SchemaHelpers/SchemaUtils.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/Machine.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/MachineUtils.cxx
    ${SRC_DIR}/LocalHelpers/VirtualTable/Helper/AvroHelper.cxx
    ${SRC_DIR}/LocalHelpers/VirtualTable/VirtualTable.cxx
    ${SRC_DIR}/MessageProcessing/Beholder/Beholder.cxx
    ${SRC_DIR}/MessageProcessing/MsgProcessor/MsgProcessor.cxx
)

# Loop through the library directories and add them using add_subdirectory
foreach(lib_dir ${LIB_DIRS})
    add_subdirectory(${lib_dir})
endforeach()

# Use find_library to locate libavrocpp.so in /usr/local/lib
find_library(AVROCPP_LIBRARY
    NAMES avrocpp
    PATHS /usr/lib/
)

add_library(beholder SHARED ${MAIN_SOURCES})
target_link_libraries(beholder PRIVATE ${AVROCPP_LIBRARY})

# Generate the .so file
if(UNIX AND NOT APPLE)
    set_target_properties(beholder PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_DIR}/src"
        PREFIX "lib"
    )
endif()

# Set the installation path for your library and headers
install(TARGETS beholder
    LIBRARY DESTINATION ${LIB_PATH}  # You can change this destination as needed
    ARCHIVE DESTINATION ${LIB_PATH}
)  # Specify the desired installation directory for libraries

