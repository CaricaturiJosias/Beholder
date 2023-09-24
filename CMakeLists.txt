cmake_minimum_required(VERSION 3.12)
project(Beholder)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(PROJECT_DIR "$ENV{HOME}/Dev/Beholder")

# Include the CMakeLists.txt inside the subdirectories
# Generate all libraries and classes
add_subdirectory(src)
# Install them and compiles the main code
add_subdirectory(CORBA)
