#include "Window.hpp"

Window::Window(int width, int height, const char *title)
{
	if (!glfwInit())
		throw std::runtime_error("glfwInit() failed.");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!_window) {
		glfwTerminate();
		throw std::runtime_error("glfwCreateWindow() failed.");
	}

	glfwMakeContextCurrent(_window);

	if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
		glfwDestroyWindow(_window);
		glfwTerminate();
		throw std::runtime_error("gladLoadGL() failed.");
	}
}

Window::~Window()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

bool	Window::shouldClose() const
{
	return (glfwWindowShouldClose(_window));
}

void	Window::pollEvents() const
{
	glfwPollEvents();
}

void	Window::swapBuffers() const
{
	glfwSwapBuffers(_window);
}
