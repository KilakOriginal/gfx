#ifndef GFX_WINDOW_HPP_
#define GFX_WINDOW_HPP_

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <string>

namespace gfx
{
    class GFXwindow
    {
        public:
            GFXwindow(const int width,
                    const int height,
                    const std::string title);
            ~GFXwindow();

            const bool shouldClose() const;
            GLFWwindow* get() const;

        private:
            void initWindow();

            const int width, height;
            const std::string windowTitle;
            GLFWwindow* window;
    };
}

#endif // GFX_WINDOW_HPP_

