# CMakeLists.txt in src/LocalHelpers

# Define a library for the LocalHelpers component
add_library(LocalHelpers SHARED
    MachineUtils/SchemaHelpers/SchemaHandler.cxx
    MachineUtils/Machine.cxx
    VirtualTable/Helper/AvroHelper.cxx
    VirtualTable/VirtualTable.cxx
)

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

# Set the installation path for your library and headers
install(TARGETS LocalHelpers
        DESTINATION lib)  # Specify the desired installation directory for libraries

install(FILES 
    MachineUtils/SchemaHelpers/GeneratedHeaders/AnalogData.hh
    MachineUtils/SchemaHelpers/GeneratedHeaders/DigitalData.hh
    MachineUtils/SchemaHelpers/SchemaHandler.hxx
    MachineUtils/MachineUtils.hxx
    MachineUtils/Machine.hxx
    VirtualTable/Helper/AvroHelper.hxx
    VirtualTable/VirtualTable.hxx
    DESTINATION include)  # Specify the desired installation directory for headers
