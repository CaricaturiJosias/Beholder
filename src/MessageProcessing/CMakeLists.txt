# CMakeLists.txt in src/MessageProcessing

set (SOURCES
    Beholder/Beholder.cxx
    MsgProcessor/MsgProcessor.cxx
)

set (HEADERS
    Beholder/Beholder.hxx
    MsgProcessor/MsgProcessor.hxx
)

# Define a library for the MessageProcessing component
add_library(MessageProcessing SHARED ${SOURCES})

# Include directories if needed (replace 'include' with your actual include directory)
target_include_directories(MessageProcessing PUBLIC lib)

# Specify the installation directories
install(TARGETS MessageProcessing
    LIBRARY DESTINATION ${LIB_PATH}  # You can change this destination as needed
    ARCHIVE DESTINATION ${LIB_PATH}
)

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)
