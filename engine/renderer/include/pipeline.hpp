/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#pragma once

#include "device.hpp"

// STD
#include <string>
#include <vector>

namespace Umbra::Renderer
{

    struct PipelineConfigInfo{};

    class Pipeline
    {
        public:
            Pipeline(Device& device, const std::string& vertShaderPath, const std::string& fragShaderPath, const PipelineConfigInfo& config);
            ~Pipeline() = default;
            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
        private:
            static std::vector<char> readFile(const std::string& filePath);
            void CreateGraphicsPipeline(const std::string& vertShaderPath, const std::string& fragShaderPath, const PipelineConfigInfo& config);
            void CreateShaderModule(const std::vector<char>& code, VkShaderModule* ShaderModule);
            Device& device;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
} // namespace Umbra::Renderer
