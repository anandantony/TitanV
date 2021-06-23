#include "first_app.hpp"

namespace titan
{
    void FirstApp::run()
    {
        while (!titanWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
}