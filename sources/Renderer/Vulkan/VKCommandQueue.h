/*
 * VKCommandQueue.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2017 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_VK_COMMAND_QUEUE_H
#define LLGL_VK_COMMAND_QUEUE_H


#include <LLGL/CommandQueue.h>
#include "Vulkan.h"
#include "VKPtr.h"
#include "VKCore.h"
#include "RenderState/VKFence.h"


namespace LLGL
{


class VKCommandQueue : public CommandQueue
{

    public:

        /* ----- Common ----- */

        VKCommandQueue(const VKPtr<VkDevice>& device, VkQueue graphicsQueue);

        /* ----- Command queues ----- */

        void Submit(CommandBuffer& commandBuffer) override;

        /* ----- Fences ----- */

        void Submit(Fence& fence) override;

        bool WaitForFence(Fence& fence, std::uint64_t timeout) override;
        void WaitForFinish() override;

    private:

        VkDevice    device_;
        VkQueue     graphicsQueue_  = VK_NULL_HANDLE;

        VKFence     globalFence_; // global fence used for "WaitForFinish" function

};


} // /namespace LLGL


#endif



// ================================================================================