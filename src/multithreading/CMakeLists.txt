set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads)
add_executable(multithreading main.cpp)
target_link_libraries (multithreading Threads::Threads)