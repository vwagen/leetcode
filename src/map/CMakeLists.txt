add_library(map_cases SHARED
    two_sum.cc
)

install(TARGETS map_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
