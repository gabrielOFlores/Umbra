/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#pragma once

// STD
#include <string>
#include <stdexcept>

// Engine Members
#include "../../windowing/include/window.hpp"

namespace Umbra::Core
{
    class ApplicationControl
    {
        public:
            ApplicationControl(std::string name) {};
            ~ApplicationControl() = default;
            void run();
        private:
            std::string name;
            Windowing::Window window{name, 1360, 768};
    };
} // namespace Umbra::Core
