#pragma once

#include "titan_device.hpp"
#include "titan_pipeline.hpp"
#include "titan_swap_chain.hpp"
#include "titan_window.hpp"
#include "titan_model.hpp"

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
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        void recordCommandBuffer(int imageIndex);

        TitanWindow titanWindow{WIDTH, HEIGHT, "Main Window"};
        TitanDevice titanDevice{titanWindow};
        std::unique_ptr<TitanSwapChain> titanSwapChain;
        std::unique_ptr<TitanPipeline> titanPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<TitanModel> titanModel;
    };
} // namespace titan