cmake_minimum_required(VERSION 3.14)

project(demo)

add_executable(pb pb.c)
add_executable(multipb multipb.c)

add_compile_options(-lpthread -Wall -g)

find_package(Threads)
TARGET_LINK_LIBRARIES(pb ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(multipb ${CMAKE_THREAD_LIBS_INIT})