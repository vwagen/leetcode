add_library(sorting_cases SHARED
    92_reverse_link_list_ii.cc
    56_merge_intervals.cc
    57_insert_interval.cc
    4_median_of_two_sorted_arrays.cc
    75_sort_colors.cc
    147_insertion_sort_list.cc
    148_sort_list.cc
)

install(TARGETS sorting_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
