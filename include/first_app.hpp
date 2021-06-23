#pragma once

#include "titan_window.hpp"
#include "titan_pipeline.hpp"

namespace titan
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        TitanWindow titanWindow{WIDTH, HEIGHT, "Main Window"};
        TitanPipeline titanPipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
    };
}