# CMakeLists.txt in src/DataModels

# Define a library for the DataModels component
add_library(DataModels SHARED
    Information/Information.cxx
    Msg/Base/BaseMsg.cxx
    Msg/GenericMsg.cxx
    Msg/SOAPMsg.cxx
)

set (HEADERS
    Information/Information.hxx
    Msg/Base/BaseMsg.hxx 
    Msg/GenericMsg.hxx
    Msg/SOAPMsg.hxx
)

# Include directories for the DataModels component
target_include_directories(DataModels PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to DataModelsLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(DataModelsMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


# Set the installation path for your library and headers
install(TARGETS DataModels
    LIBRARY DESTINATION ${LIB_PATH}  # You can change this destination as needed
    ARCHIVE DESTINATION ${LIB_PATH}
)  # Specify the desired installation directory for libraries

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)
