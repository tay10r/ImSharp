#include "imsharp_global.h"

#include <GLFW/glfw3.h>

imsharp_boolean_int imsharp_global_init()
{
	if (glfwInit() != GLFW_TRUE)
		return IMSHARP_FALSE;

	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	return IMSHARP_TRUE;
}

void imsharp_global_cleanup()
{
	glfwTerminate();
}

void imsharp_poll_events()
{
	glfwPollEvents();
}
