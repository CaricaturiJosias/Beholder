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
    LIBRARY DESTINATION /usr/local/lib  # You can change this destination as needed
    ARCHIVE DESTINATION /usr/local/lib
)

# Install header files if you have any
foreach(header ${HEADERS})
    install(DIRECTORY /include
            DESTINATION /usr/local/include  # You can change this destination as needed
    )
endforeach()
