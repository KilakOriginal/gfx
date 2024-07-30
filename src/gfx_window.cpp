#include "gfx_window.hpp"
#include <GLFW/glfw3.h>

namespace gfx
{
    GFXwindow::GFXwindow(const int width,
            const int height,
            const std::string title)
        : width(width), height(height), windowTitle(title)
    { this->initWindow(); }

    GFXwindow::~GFXwindow()
    {
        glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    const bool GFXwindow::shouldClose() const
    {
        return glfwWindowShouldClose(this->window);
    }

    GLFWwindow* GFXwindow::get() const
    {
        return this->window;
    }

    void GFXwindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        this->window = glfwCreateWindow(this->width,
                this->height,
                this->windowTitle.c_str(),
                nullptr,
                nullptr);
    }
}

