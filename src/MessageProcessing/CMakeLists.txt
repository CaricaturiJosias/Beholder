cmake_minimum_required(VERSION 3.16)

project(MessageProcessingBuild LANGUAGES CXX)

set(CMAKE_BINARY_DIR ../CMAKE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Sender ./Actors/Sender.cxx)
add_executable(Beholder ./Beholder/Beholder.cxx)
add_executable(MsgProcessor ./MsgProcessor/MsgProcessor.cxx)
