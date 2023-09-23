cmake_minimum_required(VERSION 3.12)
project(servidor)

# Define a library for the servidor component
add_library(servidorLib STATIC
    servidor.cpp
)

# Include directories for the servidor component
target_include_directories(servidorLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Define a target for the Makefile in this directory (if needed)
add_custom_target(servidorMakeFile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


