/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#pragma once

// STD
#include <string>
#include <stdexcept>

// Engine Members
#include "../../windowing/include/window.hpp"
#include "../../renderer/include/pipeline.hpp"
#include "../../renderer/include/device.hpp"

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
            static constexpr int WIDTH = 1360;
            static constexpr int HEIGHT = 768;
            Windowing::Window window{name, WIDTH, HEIGHT};
            Renderer::Device device{window};
            Renderer::Pipeline pipeline{device, "../engine/renderer/shaders/base.vert.spv", "../engine/renderer/shaders/base.frag.spv", Renderer::Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
} // namespace Umbra::Core
