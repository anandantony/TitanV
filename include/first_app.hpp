#pragma once

#include "titan_device.hpp"
#include "titan_pipeline.hpp"
#include "titan_swap_chain.hpp"
#include "titan_window.hpp"

// std
#include <memory>
#include <vector>

namespace titan
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        TitanWindow titanWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        TitanDevice titanDevice{titanWindow};
        TitanSwapChain titanSwapChain{titanDevice, titanWindow.getExtent()};
        std::unique_ptr<TitanPipeline> titanPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
} // namespace titan