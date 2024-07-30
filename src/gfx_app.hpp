#ifndef GFX_APP_HPP_
#define GFX_APP_HPP_

#include "gfx_window.hpp"

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
    };
}

#endif // GFX_APP_HPP_

