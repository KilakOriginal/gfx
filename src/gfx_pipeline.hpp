#ifndef GFX_PIPELINE_
#define GFX_PIPELINE_

#include <string>
#include <vector>
namespace gfx
{
    class GFXpipeline
    {
        public:
            GFXpipeline(const std::string& vertPath,
                    const std::string& fragPath);

        private:
            static std::vector<char> readFile(const std::string& path);
            void createGraphicsPipeline(const std::string& vertPath,
                    const std::string& fragPath);
    };
}

#endif // GFX_PIPELINE_
