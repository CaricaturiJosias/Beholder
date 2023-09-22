# CMakeLists.txt in src/Entities

# Define a library for the Entities component
add_library(EntitiesLib STATIC
    Base/Entity.cxx
    EntityManager.cxx
)

# Include directories for the Entities component
target_include_directories(EntitiesLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to EntitiesLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(EntitiesMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
