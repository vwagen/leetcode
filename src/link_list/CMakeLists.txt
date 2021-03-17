add_library(link_list_cases SHARED
    add_two_numbers.cc
)

install(TARGETS link_list_cases
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
