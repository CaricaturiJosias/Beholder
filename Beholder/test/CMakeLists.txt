# CMakeLists.txt in Beholder/test

cmake_minimum_required(VERSION 3.22)
PROJECT(test)

find_package(GTest REQUIRED)

# Specify the path to your library
set(LIB_PATH "/home/cezario/lib/")
# Find the library
find_library(Beholder
    NAMES Beholder
    PATHS ${LIB_PATH}
)

find_library(AVROCPP_LIBRARY
    NAMES avrocpp
    PATHS /usr/lib/
)

if(NOT Beholder)
    message(FATAL_ERROR "Beholder library not found")
endif()

set (SOURCES
    main.cxx
    AvroTest/ApacheAvroTest.cxx
    LocalHelpers/LocalHelpersTest.cxx
    DataModels/InformationTest.cxx
    DataModels/MsgTest.cxx
    # Entity/EntityTest.cxx
)

add_executable(test.exe ${SOURCES})

target_link_libraries(test.exe ${GTEST_LIBRARIES})
target_link_libraries(test.exe ${Beholder})
target_link_libraries(test.exe ${AVROCPP_LIBRARY})

target_include_directories(test.exe PRIVATE /usr/include/Beholder/)

enable_testing()
add_test(add text.exe)