cmake_minimum_required(VERSION 3.12)
project(CORBA)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set (CORBA_DIR "${PROJECT_DIR}/CORBA")

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

link_directories(
    ${ACE_ROOT}/lib
)

set(IDL_FILES ${IDLDIR}/Beholder.idl)
set(COMMON_FILES )

# Specify the path to your .GNU file
set(ACE_CONFIG_PATH "${ACE_ROOT}/include/makeinclude/platform_macros.GNU")

# Check if the file exists
if (EXISTS ${ACE_CONFIG_PATH})
    # Add a custom command to copy the file to the build directory
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/platform_macros.GNU
        COMMAND ${CMAKE_COMMAND} -E copy ${ACE_CONFIG_PATH} ${CMAKE_CURRENT_BINARY_DIR}/platform_macros.GNU
        COMMENT "Copying .GNU file to build directory"
    )

    # Add a custom target to ensure the file is copied before building
    add_custom_target(imported_gnu_file DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/platform_macros.GNU)

    # Set the path to the copied .GNU file as a variable
    set(IMPORTED_GNU_FILE ${CMAKE_CURRENT_BINARY_DIR}/platform_macros.GNU)
    message("The .GNU file does exist: ${ACE_CONFIG_PATH}")
else()
    message(FATAL_ERROR "The .GNU file does not exist: ${ACE_CONFIG_PATH}")
endif()


## Rules for stubs/skeletons (not needed for CMake, handled manually).

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

# Build src/ project as it is needed for the CORBA ones
message("Building the source files")
add_custom_target(BuildBeholder
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target src
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Libraries from the src should be here
set( LIB_FOLDER "${CORBA_DIR}/common/lib")

set(LIBRARIES 
        lib3PP.a
        libDataModels.a
        libEntities.a
        libLocalHelpers.a
        libMessageProcessing.a
)

# Set list of library paths.
foreach(lib ${LIBRARIES})
    list(APPEND LIBRARY_PATHS "${LIB_FOLDER}/${lib}" )
endforeach()

# Include subdirectories for each component
add_subdirectory(cliente)
add_subdirectory(servidor)
