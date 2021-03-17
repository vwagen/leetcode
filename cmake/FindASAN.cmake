# Find AddressSanitizer libraries
#
# The following variables are set:
# ASAN_FOUND - If AddressSanitizer was found
# ASAN_LIBRARIES - Path to the libasan library

find_library(ASAN_LIBRARIES NAMES libasan.so libasan.a PATHS "/opt/rh/devtoolset-7/root/lib/gcc/x86_64-redhat-linux/7/")

if (ASAN_LIBRARIES)
  message(STATUS "Found AddressSanitizer libraries: ${ASAN_LIBRARIES}")
  set(ASAN_FOUND TRUE CACHE INTERNAL "")
else()
  message(STATUS "Could not find AddressSanitizer")
endif()
