
cmake_minimum_required(VERSION 3.10.2)
set (CMAKE_CXX_STANDARD 11)


project(list)
add_executable(list test.cpp)
target_include_directories(list PUBLIC ./)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(list Threads::Threads)