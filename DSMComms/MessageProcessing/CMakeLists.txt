# CMakeLists.txt in DSMComms/MessageProcessing

include_directories( PRIVATE ${SRC_DIRS} )

set (LOCAL_SOURCES
    Beholder/Beholder.cxx
    MsgProcessor/MsgProcessor.cxx
)

set (HEADERS
    Beholder/Beholder.hxx
    MsgProcessor/MsgProcessor.hxx
)

# Define a library for the MessageProcessing component
add_library(MessageProcessing SHARED ${LOCAL_SOURCES} ${HEADERS})

# Specify dependencies for the 'install' target
install(
    FILES ${HEADERS}
    DESTINATION ${INC_PATH}
)
