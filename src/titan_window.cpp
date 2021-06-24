#include "titan_window.hpp"

// std
#include <stdexcept>

namespace titan
{

    TitanWindow::TitanWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
    {
        initWindow();
    }

    TitanWindow::~TitanWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void TitanWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

    void TitanWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to craete window surface");
        }
    }

    void TitanWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto titanWindow = reinterpret_cast<TitanWindow *>(glfwGetWindowUserPointer(window));
        titanWindow->framebufferResized = true;
        titanWindow->width = width;
        titanWindow->height = height;
    }
} // namespace titan
