# CMakeLists.txt in src/LocalHelpers

# Define a library for the LocalHelpers component
add_library(LocalHelpersLib STATIC
    MachineUtils/SchemaHelpers/SchemaHandler.cxx
    MachineUtils/Machine.cxx
    VirtualTable/Helper/AvrosHelper.cxx
    VirtualTable/VirtualTable.cxx
)

# Include directories for the LocalHelpers component
target_include_directories(LocalHelpersLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to LocalHelpersLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(LocalHelpersMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
