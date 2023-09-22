# CMakeLists.txt in src/MessageProcessing

# Define a library for the MessageProcessing component
add_library(MessageProcessingLib STATIC
    Beholder/Beholder.cxx
    MsgProcessor/MsgProcessor.cxx
)

# Include directories for the MessageProcessing component
target_include_directories(MessageProcessingLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link any required libraries (if any) to MessageProcessingLib

# Define a target for the Makefile in this directory (if needed)
add_custom_target(MessageProcessingMakefile
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
