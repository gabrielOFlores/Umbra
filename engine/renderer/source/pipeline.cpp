/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#include "../include/pipeline.hpp"

// STD
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace Umbra::Renderer
{
    Pipeline::Pipeline(Device& device, const std::string& vertShaderPath, const std::string& fragShaderPath, const PipelineConfigInfo& config) : device{device}
    {
        CreateGraphicsPipeline(vertShaderPath, fragShaderPath, config);
    }

    std::vector<char> Pipeline::readFile(const std::string& filePath)
    {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};
        if (!file.is_open())
        {
            throw std::runtime_error("Error: Unable to open file: " + filePath);
        }
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }
    
    void Pipeline::CreateGraphicsPipeline(const std::string& vertShaderPath, const std::string& fragShaderPath, const PipelineConfigInfo& config)
    {
        auto vertCode = readFile(vertShaderPath);
        auto fragCode = readFile(fragShaderPath);
    }

    void Pipeline::CreateShaderModule(const std::vector<char>& code, VkShaderModule* ShaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(device.device(), &createInfo, nullptr, ShaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("Error: Failed to create shader module.");
        }
    }

    PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo config{};
        return config;
    }
} // namespace Umbra::Renderer
