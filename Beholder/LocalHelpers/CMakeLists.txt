# CMakeLists.txt in Beholder/LocalHelpers

include_directories( PRIVATE ${SRC_DIRS} )

set (HEADERS
    MachineUtils/SchemaHelpers/AnalogData.hh
    MachineUtils/SchemaHelpers/DigitalData.hh
    MachineUtils/SchemaHelpers/SchemaUtils.hxx
    MachineUtils/MachineUtils.hxx
    MachineUtils/Machine.hxx
    VirtualTable/VirtualTable.hxx
)

# Define a library for the LocalHelpers component
set(LOCAL_SOURCES
    MachineUtils/SchemaHelpers/SchemaUtils.cxx
    MachineUtils/Machine.cxx
    VirtualTable/VirtualTable.cxx
)

add_library(LocalHelpers SHARED ${LOCAL_SOURCES})

# Include directories for the LocalHelpers component
target_include_directories(LocalHelpers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to LocalHelpers

# Define a target for the Makefile in this directory (if needed)
add_custom_target(LocalHelpersMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)
