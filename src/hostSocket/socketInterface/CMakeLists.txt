add_subdirectory(clientConnection)
add_library (
    socketInterface
    socketInterface.h
    socketInterface.cpp
)
target_link_libraries(socketInterface PRIVATE clientConnection)