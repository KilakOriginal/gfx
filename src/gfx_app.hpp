#ifndef GFX_APP_HPP_
#define GFX_APP_HPP_

#include "gfx_window.hpp"
#include "gfx_pipeline.hpp"

namespace gfx
{
    class GFXapp
    {
        public:
            static constexpr int WIDTH = 800, HEIGHT = 600;

            GFXapp();
            ~GFXapp();

            void run() const;

        private:
            GFXwindow window{WIDTH, HEIGHT, "App"};
            GFXpipeline pipeline{"/home/malik/MEGA/Code/gfx/gfx/src/shaders/simple_shader.vert.spv",
                "/home/malik/MEGA/Code/gfx/gfx/src/shaders/simple_shader.frag.spv"};
    };
}

#endif // GFX_APP_HPP_

