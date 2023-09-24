cmake_minimum_required(VERSION 3.12)
project(cliente)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Define a library for the cliente component
set(SOURCES
    cliente.cpp
)

add_executable(cliente ${SOURCES})

# Add dependencies to your targets that need the .GNU file
add_dependencies(cliente imported_gnu_file)

target_link_libraries(cliente
    ACE
    TAO
    TAO_CosNaming
    TAO_AnyTypeCode
    TAO_IORTable
)

target_link_libraries(cliente ${LIBRARY_PATHS})

# Define compiler flags
set(CPPFLAGS "")
set(LDFLAGS "")

# Include directories
foreach(d ${INCLUDES})
    target_include_directories(cliente PRIVATE ${d})
endforeach()

# Link directories
foreach(d ${LIB_DIRS})
    target_link_directories(cliente PRIVATE ${d})
endforeach()

# Additional compiler flags (if needed)
# Example:
# set(CPPFLAGS "${CPPFLAGS} -Wno-tautological-undefined-compare")

# Additional linker flags (if needed)
# Example:
# set(LDFLAGS "${LDFLAGS} -ladditional_library")

# Set compiler and linker flags for the target
set_target_properties(cliente PROPERTIES COMPILE_FLAGS "${CPPFLAGS}")
set_target_properties(cliente PROPERTIES LINK_FLAGS "${LDFLAGS}")

# Assuming you have a list of IDL files in a variable IDL_FILES, e.g., set(IDL_FILES Beholder.idl)

# Make sure generating stubs/skeletons happens before building the target
add_dependencies(cliente generate_stubs_skeletons)

# Make sure generating src/ code happens before building the target
add_dependencies(cliente BuildBeholder)
