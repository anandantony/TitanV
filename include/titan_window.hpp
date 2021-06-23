#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace titan
{

    class TitanWindow
    {
    public:
        TitanWindow(int w, int h, std::string name);
        ~TitanWindow();

        TitanWindow(const TitanWindow &) = delete;
        TitanWindow &operator=(const TitanWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); };

    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}