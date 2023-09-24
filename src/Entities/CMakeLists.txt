# CMakeLists.txt in src/Entities

# Define a library for the Entities component
add_library(Entities SHARED
    Base/Entity.cxx
    EntityManager.cxx
)

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

# Set the installation path for your library and headers
install(TARGETS Entities
    LIBRARY DESTINATION ${LIB_PATH}  # You can change this destination as needed
    ARCHIVE DESTINATION ${LIB_PATH}
)  # Specify the desired installation directory for libraries

install(FILES 
        Base/Entity.hxx
        EntityManager.hxx
        DESTINATION include)  # Specify the desired installation directory for headers
