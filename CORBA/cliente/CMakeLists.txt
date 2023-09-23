cmake_minimum_required(VERSION 3.12)
project(cliente)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Define a library for the cliente component
set(SOURCES
    cliente.cpp
)

if (NOT DEFINED ACE_ROOT)
    set (ACE_ROOT "/home/cezario/Dev/ACE_wrappers")
endif()

if (NOT DEFINED TAO_ROOT)
    set(TAO_ROOT "/home/cezario/Dev/ACE_wrappers/TAO")
endif()

set(BINDIR "../bin")
set(IDLDIR "../idl")
set(COMMONDIR "../common")

set(INCLUDES
    ${IDLDIR}
    ${ACE_ROOT}
    ${TAO_ROOT}
    ${TAO_ROOT}/orbsvc
    ${COMMONDIR}
)

include(${ACE_ROOT}/include/makeinclude/ACEConfig.cmake.in)

link_directories(
    ${ACE_ROOT}/lib
)

set(IDL_FILES ${IDLDIR}/Beholder.idl)
set(COMMON_FILES )

add_executable(cliente ${SOURCES})

target_link_libraries(cliente
    ACE
    TAO
    TAO_CosNaming
    TAO_AnyTypeCode
    TAO_IORTable
)

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

# Rules for stubs/skeletons (not needed for CMake, handled manually).

# Assuming you have a list of IDL files in a variable IDL_FILES, e.g., set(IDL_FILES Beholder.idl)

# Create a custom target to generate stubs/skeletons
add_custom_target(generate_stubs_skeletons
    DEPENDS ${IDL_FILES}  # Add your IDL files as dependencies
)

# Add a custom command to generate stubs/skeletons for each IDL file
foreach(IDL_FILE ${IDL_FILES})
    get_filename_component(IDL_FILENAME ${IDL_FILE} NAME)
    add_custom_command(
        OUTPUT ${IDL_FILENAME}C.cpp
        COMMAND tao_idl -Gstl -w -I${IDLDIR} -o ${IDLDIR} ${IDL_FILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${IDL_FILE}
        message("Generating stubs/skeletons for ${IDL_FILENAME}")
    )
endforeach()

# Add the generated files to the list of sources for the target
set(GENERATED_FILES)
foreach(IDL_FILE ${IDL_FILES})
    get_filename_component(IDL_FILENAME ${IDL_FILE} NAME_WE)
    list(APPEND GENERATED_FILES ${IDL_FILENAME}C.cpp)
endforeach()

# Make sure generating stubs/skeletons happens before building the target
add_dependencies(cliente generate_stubs_skeletons)

# Build src/ project
add_custom_target(BuildBeholder
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target src
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building Beholder"
)

# Make sure generating src/ code happens before building the target
add_dependencies(cliente BuildBeholder)
