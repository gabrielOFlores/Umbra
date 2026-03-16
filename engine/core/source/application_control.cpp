/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#include "../include/application_control.hpp"

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
