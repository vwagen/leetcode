add_library(map_cases SHARED
    1_two_sum.cc
)

install(TARGETS map_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
