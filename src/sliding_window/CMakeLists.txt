add_library(sliding_window_cases SHARED
    3_len_of_longest_substr.cc
)

install(TARGETS sliding_window_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
