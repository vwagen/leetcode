cmake_minimum_required(VERSION 3.1)
project(VWagenLeetCode)
set (CMAKE_CXX_STANDARD 14)

include_directories(include)

set(LEETCODE_LIBDIR lib CACHE PATH "" FORCE)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/${LEETCODE_LIBDIR})

add_subdirectory(src)
