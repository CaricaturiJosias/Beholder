# CMakeLists.txt in src/DataModels

# Define a library for the DataModels component
add_library(DataModelsLib STATIC
    Information/Information.cxx
    Msg/Base/BaseMsg.cxx
    Msg/GenericMsg.cxx
    Msg/SOAPMsg.cxx
)

# Include directories for the DataModels component
target_include_directories(DataModelsLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to DataModelsLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(DataModelsMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

