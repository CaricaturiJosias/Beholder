# CMakeLists.txt in src/Entities

include_directories( PRIVATE ${SRC_DIRS} )

# Define a library for the Entities component
set (HEADERS 
    Base/Entity.hxx
    EntityManager.hxx
)

set(LOCAL_SOURCES
    Base/Entity.cxx
    EntityManager.cxx
)

add_library(Entities SHARED ${LOCAL_SOURCES})

# Include directories for the Entities component
target_include_directories(Entities PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to Entities

# Define a target for the Makefile in this directory (if needed)
add_custom_target(EntitiesMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)