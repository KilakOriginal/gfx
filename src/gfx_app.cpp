#include "gfx_app.hpp"
#include <GLFW/glfw3.h>

namespace gfx
{
    GFXapp::GFXapp() = default;
    GFXapp::~GFXapp() = default;

    void GFXapp::run() const
    {
        glfwMakeContextCurrent(this->window.get());
        while (!this->window.shouldClose())
        {
            glfwPollEvents();
            glfwSwapBuffers(this->window.get());
        }
    }
}

