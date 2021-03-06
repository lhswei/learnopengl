#include "include.h"

int main()
{
	glfw_init();
	GLFWwindow* window = create_window();
	if (window == NULL)
	{
		return -1;
	}


	fbuffer_init();

    // render loop
    // -----------
    while(!glfwWindowShouldClose(window))
    {
		fbuffer_loop(window);
    }

	fbuffer_end();
    glfwTerminate();
    return 0;
}

