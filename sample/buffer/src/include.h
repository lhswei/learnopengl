#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern void glfw_init(void);
extern GLFWwindow* create_window(void);

extern void zbuffer_init();
extern void zbuffer_loop(GLFWwindow* window);
extern void zbuffer_end();

extern void sbuffer_init();
extern void sbuffer_loop(GLFWwindow* window);
extern void sbuffer_end();

#endif // _INCLUDE_H_
