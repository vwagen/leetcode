add_library(utils SHARED
    utils.cc
)

install(TARGETS utils
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION libstatic)
