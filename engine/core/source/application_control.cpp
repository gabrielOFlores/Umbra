/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#include "../include/application_control.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Umbra::Core
{
    void ApplicationControl::run()
    {
        while (!window.ShouldClose())
        {
            glfwPollEvents();
            
        }
        
    }
} // namespace Umbra::Core
