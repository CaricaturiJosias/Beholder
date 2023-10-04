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

set(BINDIR "${CORBA_DIR}/bin")
set(IDLDIR "${CORBA_DIR}/idl")
set(COMMONDIR "${CORBA_DIR}/common")

link_directories(
    $ENV{ACE_ROOT}/ace
    $ENV{ACE_ROOT}/lib
    $ENV{ACE_ROOT}
    $ENV{TAO_ROOT}/tao
    $ENV{TAO_ROOT}/lib
    $ENV{ACE_ROOT}
)

set(IDL_FILES ${IDLDIR}/Beholder.idl)
set(COMMON_FILES )

set(INCLUDES
    ${IDLDIR}
    $ENV{ACE_ROOT}
    "$ENV{ACE_ROOT}/ace"
    $ENV{TAO_ROOT}
    "$ENV{TAO_ROOT}/tao"
    "$ENV{ACE_ROOT}/lib"
    "$ENV{TAO_ROOT}/lib"
    "$ENV{ACE_ROOT}/include"
    "$ENV{TAO_ROOT}/include"
    ${TAO_ROOT}/orbsvc
)

## Rules for stubs/skeletons (not needed for CMake, handled manually).

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

# Create a custom target to generate stubs/skeletons
add_custom_target(generate_stubs_skeletons
    DEPENDS ${IDL_FILES}  # Add your IDL files as dependencies
)

# Add the generated files to the list of sources for the target
set(GENERATED_FILES)
foreach(IDL_FILE ${IDL_FILES})
    get_filename_component(IDL_FILENAME ${IDL_FILE} NAME_WE)
    list(APPEND GENERATED_FILES ${IDLDIR}/${IDL_FILENAME}C.cpp)
endforeach()

# Build DSMComms/ project as it is needed for the CORBA ones
message("Building the source files")
add_custom_target(BuildBeholder
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target DSMComms
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# For cliente
include(ExternalProject)

# ExternalProject_Add(
#     cliente
#     PREFIX ${PROJECT_DIR}/build/cliente/
#     DOWNLOAD_COMMAND ""  # No download step, since it's already in the source tree
#     CONFIGURE_COMMAND ""
#     BUILD_COMMAND make -C ${CORBA_DIR}/cliente/ 
#     INSTALL_COMMAND make -C ${CORBA_DIR}/cliente/ install
# )

# # For servidor
# ExternalProject_Add(
#     servidor
#     PREFIX ${PROJECT_DIR}/build/servidor/
#     DOWNLOAD_COMMAND ""  # No download step, since it's already in the source tree
#     CONFIGURE_COMMAND ""
#     BUILD_COMMAND make -C ${CORBA_DIR}/servidor
#     INSTALL_COMMAND make -C ${CORBA_DIR}/servidor/ install
# )
