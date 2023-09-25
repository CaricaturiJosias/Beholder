# CMakeLists.txt in src/ (Main CMakeLists.txt)

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Beholder)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set (LIB_PATH "/usr/local/lib/beholder/")
set (INC_PATH "/usr/local/include/beholder/")

# Check if the folder exists
if(NOT EXISTS "${LIB_PATH}")
    # Create the folder if it doesn't exist
    file(MAKE_DIRECTORY "${LIB_PATH}")
endif()

if(NOT EXISTS "${INC_PATH}")
    # Create the folder if it doesn't exist
    file(MAKE_DIRECTORY "${INC_PATH}")
endif()

set(LIB_DIRS
    DataModels
    Entities
    3PP
    MessageProcessing
    LocalHelpers        
)

# Loop through the library directories and add them using add_subdirectory
foreach(lib_dir ${LIB_DIRS})
    add_subdirectory(${lib_dir})
endforeach()

# Add any additional dependencies or configuration here

add_custom_target(all_libraries)
add_dependencies(all_libraries DataModels Entities 3PP MessageProcessing LocalHelpers)

set(CMAKE_INSTALL_PREFIX "../CORBA/common")
# You can also specify any custom build commands or post-build steps here
