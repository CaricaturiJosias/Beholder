# CMakeLists.txt in src/3PP

# Define a library for the 3PP component
add_library(3PP SHARED
    Pugi/pugixml.cpp
)

set (HEADERS
    "Pugi/pugixml.hpp"
    "Pugi/pugiconfig.hpp"
)

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

# Set the installation path for your library and headers
install(TARGETS 3PP
    LIBRARY DESTINATION ${LIB_PATH}  # You can change this destination as needed
    ARCHIVE DESTINATION ${LIB_PATH}
)  # Specify the desired installation directory for libraries

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)