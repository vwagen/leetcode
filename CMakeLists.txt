cmake_minimum_required(VERSION 3.1)
project(VWagenLeetCode)
set (CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(ASAN)
#find_package(TSAN)
#find_package(UBSAN)

if (ASAN_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
elseif (TSAN_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
elseif (UBSAN_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

include_directories(include)

set(LEETCODE_LIBDIR lib CACHE PATH "" FORCE)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/${LEETCODE_LIBDIR})

add_subdirectory(src)
