cmake_minimum_required(VERSION 3.12)
project(Beholder)

set(CMAKE_MAKE_PROGRAM "make --quiet")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
# TODO - Resolve this????
set(PROJECT_DIR "/home/cezario/Dev/Beholder")

# Include the CMakeLists.txt inside the subdirectories
# Generate all libraries and classes
add_subdirectory(Beholder)
# Install them and compiles the main code
add_subdirectory(DSMComms)
