# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PyramidXOTest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PyramidXOTest_autogen.dir\\ParseCache.txt"
  "PyramidXOTest_autogen"
  )
endif()
