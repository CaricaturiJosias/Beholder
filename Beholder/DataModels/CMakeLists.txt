# CMakeLists.txt in Beholder/DataModels

include_directories( PRIVATE ${SRC_DIRS} )

# Define a library for the DataModels component
set (HEADERS
    Information/Information.hxx
    Msg/Base/BaseMsg.hxx 
    Msg/GenericMsg.hxx
    Msg/SOAPMsg.hxx
)

set(LOCAL_SOURCES
    Information/Information.cxx
    Msg/Base/BaseMsg.cxx
    Msg/GenericMsg.cxx
    Msg/SOAPMsg.cxx
)

add_library(DataModels SHARED ${LOCAL_SOURCES})

# Include directories for the DataModels component
target_include_directories(DataModels PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to DataModels

# Define a target for the Makefile in this directory (if needed)
add_custom_target(DataModelsMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)
