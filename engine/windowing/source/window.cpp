/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#include "../include/window.hpp"

namespace Umbra::Windowing
{
    Window::Window(std::string title, int width, int height) : title{title}, width{width}, height{height}
    {
        CreateWindow();
    }

    Window::~Window()
    {
        glfwDestroyWindow(context);
        glfwTerminate();
    }

    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(context);
    }

    void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
    {
        if (glfwCreateWindowSurface(instance, context, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("Error: Failed to created window surface.");
        }
    }

    GLFWwindow* Window::GetContext()
    {
        return context;
    }

    void Window::CreateWindow()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Error: glfw could not be initialized.");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        context = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    }
}