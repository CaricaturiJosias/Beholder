# CMakeLists.txt in src/MessageProcessing

# Define a library for the MessageProcessing component
add_library(MessageProcessing STATIC
    Beholder/Beholder.cxx
    MsgProcessor/MsgProcessor.cxx
)

# Include directories for the MessageProcessing component
target_include_directories(MessageProcessing PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to MessageProcessing

# Define a target for the Makefile in this directory (if needed)
add_custom_target(MessageProcessingMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the installation path for your library and headers
install(TARGETS MessageProcessing
        DESTINATION lib)  # Specify the desired installation directory for libraries

install(FILES 
    Beholder/Beholder.hxx
    MsgProcessor/MsgProcessor.hxx
    DESTINATION include)  # Specify the desired installation directory for headers

