add_subdirectory(common)
add_subdirectory(map)
add_subdirectory(link_list)
add_subdirectory(sliding_window)
add_subdirectory(sorting)

add_executable(leetcode leetcode.cc)
target_link_libraries(leetcode utils)
target_link_libraries(leetcode link_list_cases)
target_link_libraries(leetcode map_cases)
target_link_libraries(leetcode sliding_window_cases)
target_link_libraries(leetcode sorting_cases)

if(ASAN_FOUND)
    target_link_libraries(leetcode ${ASAN_LIBRARIES})
elseif(TSAN_FOUND)
    target_link_libraries(leetcode ${TSAN_LIBRARIES})
elseif(UBSAN_FOUND)
    target_link_libraries(leetcode ${UBSAN_LIBRARIES})
endif()

install(TARGETS leetcode
        RUNTIME DESTINATION bin)
