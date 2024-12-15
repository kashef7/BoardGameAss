# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Sus_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Sus_autogen.dir\\ParseCache.txt"
  "Sus_autogen"
  )
endif()
