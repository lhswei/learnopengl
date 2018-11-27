#include <iostream>
#include "baselight.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

BaseLight* g_BaseLight = NULL;

int main(int argc, char* argv[])
{
	BaseLight base_light(800.0f, 600.0f);
	if (base_light.Init(argv[0], framebuffer_size_callback, mouse_callback, scroll_callback) == 0)
	{
		g_BaseLight = &base_light;
		base_light.Run();
		g_BaseLight = NULL;
	}
	base_light.UnInit();

	return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	if (g_BaseLight)
	{
		g_BaseLight->framebuffer_size_callback(window, width, height);
	}
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (g_BaseLight)
	{
		g_BaseLight->mouse_callback(window, xpos, ypos);
	}
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (g_BaseLight)
	{
		g_BaseLight->scroll_callback(window, xoffset, yoffset);
	}
}
