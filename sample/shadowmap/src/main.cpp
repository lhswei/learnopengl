#include "include.h"

int main()
{
	glfw_init();
	GLFWwindow* window = create_window();
	if (window == NULL)
	{
		return -1;
	}


    // render loop
    // -----------
    while(!glfwWindowShouldClose(window))
    {

		Sleep(1);
    }

    glfwTerminate();
    return 0;
}
