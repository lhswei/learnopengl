#ifndef _UTILITY_H_
#define _UTILITY_H_

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <learnopengl/shader.h>
#include <learnopengl/camera.h>

void glfw_init(void);
GLFWwindow* create_window(void);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(const char* path);

#endif
