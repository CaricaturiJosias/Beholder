# CMakeLists.txt in src/3PP

include_directories( PRIVATE ${SRC_DIRS} )

set (HEADERS
"Pugi/pugixml.hpp"
"Pugi/pugiconfig.hpp"
)

# Define a library for the 3PP component

set(LOCAL_SOURCES
    Pugi/pugixml.cpp
)

add_library(3PP SHARED ${LOCAL_SOURCES})

# Include directories for the 3PP component
target_include_directories(3PP PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to 3PP

# Define a target for the Makefile in this directory (if needed)
add_custom_target(3PPMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)