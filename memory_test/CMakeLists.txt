
cmake_minimum_required(VERSION 3.22)

project(TEST)

set(LOCAL_SOURCES
    main.cxx
)

# Use find_library to locate libavrocpp.so in /usr/local/lib
find_library(AVROCPP_LIBRARY
    NAMES avrocpp
    PATHS /usr/lib/
)

find_package(OpenSSL REQUIRED)

add_executable(t ${LOCAL_SOURCES})

target_link_libraries(t ${AVROCPP_LIBRARY})
target_link_libraries(t OpenSSL::SSL)

