cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/firstwin")
  add_subdirectory(firstwin)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/triangle")
  add_subdirectory(triangle)
endif()