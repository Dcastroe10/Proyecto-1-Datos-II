# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Proyecto-1-Datos-II-Daniel-C_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Proyecto-1-Datos-II-Daniel-C_autogen.dir\\ParseCache.txt"
  "Proyecto-1-Datos-II-Daniel-C_autogen"
  )
endif()
