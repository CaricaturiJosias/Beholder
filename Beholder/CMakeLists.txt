# CMakeLists.txt in Beholder/ (Main CMakeLists.txt)

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Beholder)
set(PROJECT_VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set (LIB_PATH "/home/cezario/lib/")
set (INC_PATH "/usr/include/Beholder/")

set(LIB_DIRS
    DataModels
    Entities
    3PP
    MessageProcessing
    LocalHelpers        
)

# To make simplified include
set (SRC_DIR ${CMAKE_SOURCE_DIR}/Beholder)

set(SRC_DIRS
    ${SRC_DIR}/3PP/Pugi
    ${SRC_DIR}/DataModels/Information
    ${SRC_DIR}/DataModels/Msg
    ${SRC_DIR}/DataModels/Msg/Base
    ${SRC_DIR}/Entities
    ${SRC_DIR}/Entities/Base
    ${SRC_DIR}/LocalHelpers/MachineUtils
    ${SRC_DIR}/LocalHelpers/MachineUtils/SchemaHelpers/
    ${SRC_DIR}/LocalHelpers/VirtualTable
    ${SRC_DIR}/MessageProcessing/Beholder
    ${SRC_DIR}/MessageProcessing/MsgProcessor
    # Add other include directories as needed
)
include_directories( PUBLIC ${SRC_DIRS} )

# HARDCODED BECAUSE CMAKE DOES NOT LIKE IT WHEN I TRY TO DO STUFF
set (MAIN_SOURCES
    ${SRC_DIR}/3PP/Pugi/pugixml.cpp
    ${SRC_DIR}/DataModels/Information/Information.cxx
    ${SRC_DIR}/DataModels/Msg/Base/BaseMsg.cxx
    ${SRC_DIR}/DataModels/Msg/GenericMsg.cxx
    ${SRC_DIR}/DataModels/Msg/SOAPMsg.cxx
    ${SRC_DIR}/Entities/Base/Entity.cxx
    ${SRC_DIR}/Entities/EntityManager.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/Machine.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/MachineUtils.cxx
    ${SRC_DIR}/LocalHelpers/MachineUtils/SchemaHelpers/SchemaUtils.cxx
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

add_library(Beholder SHARED ${MAIN_SOURCES})
target_include_directories(Beholder PUBLIC ${SRC_DIRS})
target_link_libraries(Beholder PRIVATE ${AVROCPP_LIBRARY})

# # Generate the .so file
# if(UNIX AND NOT APPLE)
#     set_target_properties(Beholder PROPERTIES
#         LIBRARY_OUTPUT_DIRECTORY ${LIB_PATH}
#         PREFIX "lib"
#     )
# endif()

include(GNUInstallDirs)

# Iterate through the header directories and copy header files to INC_PATH
foreach(HEADER_DIR ${SRC_DIRS})
    file(GLOB HEADER_FILES ${HEADER_DIR}/*.h)  # Adjust the extension if needed

    foreach(HEADER_FILE ${HEADER_FILES})
        # Get the relative path of the header file (stripping the source directory)
        file(RELATIVE_PATH REL_HEADER_PATH ${CMAKE_SOURCE_DIR} ${HEADER_FILE})
        
        # Define the installation path for the header file
        set(INSTALL_HEADER_PATH ${INC_PATH}/${REL_HEADER_PATH})
        
        # Copy the header file to the installation directory
        configure_file(${HEADER_FILE} ${INSTALL_HEADER_PATH} COPYONLY)
    endforeach()
endforeach()

# Set the installation path for your library and headers
install(TARGETS Beholder
    LIBRARY DESTINATION ${LIB_PATH}
    ARCHIVE DESTINATION ${LIB_PATH}
    PUBLIC_HEADER DESTINATION ${INC_PATH}
)  # Specify the desired installation directory for libraries

