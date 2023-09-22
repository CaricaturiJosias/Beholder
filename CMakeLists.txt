cmake_minimum_required(VERSION 3.12)
project(YourProjectName)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Create a build/ directory outside of src/
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${BUILD_DIR})

# Add subdirectories for each component
add_subdirectory(src/DataModels)
add_subdirectory(src/Entities)
add_subdirectory(src/Lib)
add_subdirectory(src/LocalHelpers)
add_subdirectory(src/MessageProcessing)

# Add any additional dependencies or configuration here

