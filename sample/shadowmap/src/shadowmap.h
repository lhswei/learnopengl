#ifndef _SHADOWMAP_H_
#define _SHADOWMAP_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/shader.h>
#include <learnopengl/camera.h>
#include <learnopengl/filesystem.h>

extern void processInput(GLFWwindow *window);
extern unsigned int loadTexture(const char* path);


// settings
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

// camera
extern Camera camera;
extern float lastX;
extern float lastY;
extern bool firstMouse;

// timing
extern float deltaTime;
extern float lastFrame;

#endif
