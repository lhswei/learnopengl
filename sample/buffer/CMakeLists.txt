project(buffer)
cmake_minimum_required(VERSION 2.8)

set(CLIENT_TARGET "buffer")

configure_file(${DEMON_ROOT}/configuration/root_directory.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/root_directory.h)
include_directories(${DEMON_ROOT}/configuration)

include_directories(
  ./src
  ${DEMON_INCLUDE})

file(GLOB_RECURSE CLIENT_SRC_LIST
  "${DEMON_ROOT}/leanopengl/*.cpp"
  "${DEMON_ROOT}/leanopengl/*.h"
  "${DEMON_ROOT}/leanopengl/*.c"
  "${DEMON_ROOT}/leanopengl/*.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

file(GLOB_RECURSE CLIENT_RES_LIST
	"${CMAKE_CURRENT_SOURCE_DIR}/res/*.*"
)

file(GLOB_RECURSE CLIENT_SHADER_LIST
	"${CMAKE_CURRENT_SOURCE_DIR}/shader/*.*"
)

file(GLOB_RECURSE CLIENT_GLM_LIST
	"${DEMON_ROOT}/include/glm/*.*"
)

file(GLOB_RECURSE CLIENT_LEARNOPENGL_LIST
  "${DEMON_ROOT}/include/learnopengl/*.*"
)

link_directories("${DEMON_LIB}" "${DEMON_LIB}/$<CONFIGURATION>")
link_libraries("glfw3.lib" "opengl32.lib" "glad.lib" "assimp-vc140-mt.lib")
##
add_executable(${CLIENT_TARGET} ${CLIENT_SRC_LIST} ${CLIENT_GLM_LIST} ${CLIENT_LEARNOPENGL_LIST})

source_group("src" FILES ${CLIENT_SRC_LIST})
source_group("glm" FILES ${CLIENT_GLM_LIST})
source_group("learnopengl" FILES ${CLIENT_LEARNOPENGL_LIST})

SET_TARGET_OUT_DIR(CLIENT_TARGET_OUT_DIR)

set(CLIENT_DLL_FILES "assimp-vc140-mt.dll")
set(CLIENT_DLL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dll")
COPY_FILES("${CLIENT_TARGET}" "${CLIENT_DLL_FILES}" "${CLIENT_DLL_DIR}" "${CLIENT_TARGET_OUT_DIR}")
