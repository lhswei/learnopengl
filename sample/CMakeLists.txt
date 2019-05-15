cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/firstwin")
  add_subdirectory(firstwin)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/triangle")
  add_subdirectory(triangle)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/camera")
  add_subdirectory(camera)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/light")
  add_subdirectory(light)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/instancing")
  add_subdirectory(instancing)
endif()

cmake_minimum_required(VERSION 2.8)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/buffer")
  add_subdirectory(buffer)
endif()


