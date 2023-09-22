# CMakeLists.txt in src/ (Main CMakeLists.txt)

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Beholder)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include subdirectories for each component
add_subdirectory(DataModels)
add_subdirectory(Entities)
add_subdirectory(Lib)
add_subdirectory(LocalHelpers)
add_subdirectory(MessageProcessing)

# Add any additional dependencies or configuration here

# You can also specify any custom build commands or post-build steps here
