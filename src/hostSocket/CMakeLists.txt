add_subdirectory(socketInterface)
add_executable(hostSocket main.cpp)
# target_link_libraries(hostSocket PRIVATE clientConnection)
target_link_libraries(hostSocket PRIVATE socketInterface)