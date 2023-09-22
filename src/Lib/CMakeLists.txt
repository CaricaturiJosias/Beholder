# CMakeLists.txt in src/Lib

# Define a library for the Lib component
add_library(LibLib STATIC
    Pugi/pugixml.cpp
)

# Include directories for the Lib component
target_include_directories(LibLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to LibLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(LibMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
