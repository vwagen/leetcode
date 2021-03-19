add_library(sorting_cases SHARED
    92_reverse_link_list_ii.cc
    56_merge_intervals.cc
    57_insert_interval.cc
)

install(TARGETS sorting_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
