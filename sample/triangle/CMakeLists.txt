project(triangle)
cmake_minimum_required(VERSION 2.8)

set(CLIENT_TARGET "triangle")

include_directories(
  ./src
  ${DEMON_INCLUDE})

file(GLOB_RECURSE CLIENT_SRC_LIST 
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

link_directories("${DEMON_LIB}" "${DEMON_LIB}/$<CONFIGURATION>")
link_libraries("glfw3.lib" "opengl32.lib" "glad.lib")
## 
add_executable(${CLIENT_TARGET} ${CLIENT_SRC_LIST})

source_group("src" FILES ${CLIENT_SRC_LIST})

SET_TARGET_OUT_DIR(CLIENT_TARGET_OUT_DIR)
# COPY_FILES("${CLIENT_TARGET}" "${DEMON_BINARY_FILES}" "${DEMON_BINARY_DIR}" "${CLIENT_TARGET_OUT_DIR}")