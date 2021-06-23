#include "titan_window.hpp"

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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
} // namespace titan
