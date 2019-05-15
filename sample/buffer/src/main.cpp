#include "include.h"

int main()
{
	glfw_init();
	GLFWwindow* window = create_window();
	if (window == NULL)
	{
		return -1;
	}


	sbuffer_init();

    // render loop
    // -----------
    while(!glfwWindowShouldClose(window))
    {
		sbuffer_loop(window);
    }

	sbuffer_end();
    glfwTerminate();
    return 0;
}

