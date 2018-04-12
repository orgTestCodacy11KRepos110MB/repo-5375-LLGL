/*
 * VKGraphicsPipeline.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2017 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_VK_GRAPHICS_PIPELINE_H
#define LLGL_VK_GRAPHICS_PIPELINE_H


#include <LLGL/GraphicsPipeline.h>
#include <vulkan/vulkan.h>
#include "../VKPtr.h"


namespace LLGL
{


class VKShaderProgram;

class VKGraphicsPipeline : public GraphicsPipeline
{

    public:

        VKGraphicsPipeline(
            const VKPtr<VkDevice>& device, VkRenderPass renderPass, const VkExtent2D& extent,
            const GraphicsPipelineDescriptor& desc, VkPipelineLayout defaultPipelineLayout
        );

        inline VkPipeline GetVkPipeline() const
        {
            return pipeline_.Get();
        }

        inline VkPipelineLayout GetVkPipelineLayout() const
        {
            return pipelineLayout_;
        }

    private:

        void CreateGraphicsPipeline(const GraphicsPipelineDescriptor& desc, const VkExtent2D& extent);

        VkDevice            device_         = VK_NULL_HANDLE;
        VkRenderPass        renderPass_     = VK_NULL_HANDLE;
        VkPipelineLayout    pipelineLayout_ = VK_NULL_HANDLE;
        VKPtr<VkPipeline>   pipeline_;

};


} // /namespace LLGL


#endif



// ================================================================================