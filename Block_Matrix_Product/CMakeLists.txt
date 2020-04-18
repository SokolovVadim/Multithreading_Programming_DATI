
cmake_minimum_required(VERSION 3.10.2)
set (CMAKE_CXX_STANDARD 11)

project(matrix)
add_executable(matrix test.cpp reader.cpp)
target_include_directories(matrix PUBLIC ./)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(matrix Threads::Threads)