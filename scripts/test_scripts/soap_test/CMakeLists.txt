
cmake_minimum_required(VERSION 3.22)

project(TEST)

#Here we add a Cmake Module ably to find GSOAP on your system, and find it
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
include(${CMAKE_MODULE_PATH}/FindGSOAP.cmake)  # Replace 'your_custom_functions' with the actual filename

#Create the directory that will host files generated by GSOAP
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/generated)

set (MAIN_CLIENT_SOURCE 
    ${CMAKE_BINARY_DIR}/myapp.cpp
    ${CMAKE_BINARY_DIR}/generated/soapClient.cpp
    ${CMAKE_BINARY_DIR}/generated/soapC.cpp
)

set (MAIN_SERVER_SOURCE 
    ${CMAKE_BINARY_DIR}/hello.cpp
    ${CMAKE_BINARY_DIR}/generated/soapServer.cpp
    ${CMAKE_BINARY_DIR}/generated/soapC.cpp
)

#some files are generated by gsoap
set_source_files_properties( ${CMAKE_BINARY_DIR}/generated/soapServer.cpp	 PROPERTIES GENERATED TRUE ) 
set_source_files_properties( ${CMAKE_BINARY_DIR}/generated/soapClient.cpp	 PROPERTIES GENERATED TRUE ) 
set_source_files_properties( ${CMAKE_BINARY_DIR}/generated/soapC.cpp	 PROPERTIES GENERATED TRUE ) 

#include .h folders here
include_directories( 
	${CMAKE_BINARY_DIR}/generated
)

#add the source files to the client executable
add_executable(GSOAP_SERVER ${MAIN_SERVER_SOURCE} )

#add the source files to the client executable
add_executable(GSOAP_CLIENT ${MAIN_CLIENT_SOURCE} )

#Create a cmake target that generate gsoap files
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/generated/soapClient.cpp ${CMAKE_BINARY_DIR}/generated/soapServer.cpp ${CMAKE_BINARY_DIR}/generated/soapC.cpp
    COMMAND ${GSOAP_SOAPCPP2}  -d ${CMAKE_BINARY_DIR}/generated ${CMAKE_BINARY_DIR}/hello.h 
    DEPENDS ${CMAKE_BINARY_DIR}/hello.h
    COMMENT "CREATING STUBS AND GLUE CODE"
)
    
add_custom_target(GSOAP_GENERATION_TARGET
	DEPENDS ${CMAKE_BINARY_DIR}/generated/soapClient.cpp)

#Make sure that the client is compiled only after gsoap has been processed
add_dependencies(GSOAP_CLIENT GSOAP_GENERATION_TARGET)
add_dependencies(GSOAP_SERVER GSOAP_GENERATION_TARGET)


#extra libraries for the executable
target_link_libraries(GSOAP_CLIENT PRIVATE ${GSOAP_CXX_LIBRARIES})
target_link_libraries(GSOAP_SERVER PRIVATE ${GSOAP_CXX_LIBRARIES})

target_include_directories(GSOAP_CLIENT PRIVATE ${GSOAP_INCLUDE_DIR})
target_include_directories(GSOAP_SERVER PRIVATE ${GSOAP_INCLUDE_DIR} ${GSOAP_PLUGIN_DIR})
