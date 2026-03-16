/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// STD
#include <string>
#include <stdexcept>

struct GLFWwindow;

namespace Umbra::Windowing
{
    class Window
    {
        public:
            Window(std::string title, int width, int height);
            ~Window();
            bool ShouldClose();
            void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
            GLFWwindow* GetContext();
        private:
            std::string title;
            int width;
            int height;
            GLFWwindow* context;
            void CreateWindow();
    };
} // namespace Umbra::Windowing
