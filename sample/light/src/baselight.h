#ifndef _BASE_LIGHT_H_
#define _BASE_LIGHT_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader_s.h>
#include <camera.h>

#include <string>

class BaseLight
{
public:
	BaseLight(float scr_width, float scr_height);
	~BaseLight();

	int Init(const char* root, GLFWframebuffersizefun framebuffer_size_callback, GLFWcursorposfun mouse_callback, GLFWscrollfun scroll_callback);
	void Run();
	void UnInit();

public:
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void processInput(GLFWwindow *window);

private:
	float m_width;
	float m_height;
	float m_lastX;
	float m_lastY;
	bool m_firstMouse;
	float m_deltaTime;
	float m_lastFrame;
	glm::vec3 m_lightPos;
	Camera m_camera;
	GLFWwindow* m_window;
	std::string m_rootDir;
};

#endif //_BASE_LIGHT_H_
