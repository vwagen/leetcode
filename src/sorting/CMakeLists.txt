add_library(sorting_cases SHARED
    92_reverse_link_list_ii.cc
)

install(TARGETS sorting_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
