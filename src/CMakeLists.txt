add_subdirectory(common)
add_subdirectory(map)
add_subdirectory(link_list)

add_executable(leetcode leetcode.cc)
target_link_libraries(leetcode utils)
target_link_libraries(leetcode map_cases)
target_link_libraries(leetcode link_list_cases)
install(TARGETS leetcode
        RUNTIME DESTINATION bin)
