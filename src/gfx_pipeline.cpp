#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "gfx_pipeline.hpp"

namespace gfx
{
    GFXpipeline::GFXpipeline(const std::string& vertPath,
            const std::string& fragPath)
    {
        createGraphicsPipeline(vertPath, fragPath);
    }

    std::vector<char> GFXpipeline::readFile(const std::string& path)
    {
        std::ifstream file{path, std::ios::ate | std::ios::binary};

        if (!file.is_open())
            throw std::runtime_error("failed to open file '" + path + "'");

        size_t size = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(size);

        file.seekg(0);
        file.read(buffer.data(), size);
        
        file.close();

        return buffer;
    }

    void GFXpipeline::createGraphicsPipeline(const std::string& vertPath,
            const std::string& fragPath)
    {
        auto vertCode = readFile(vertPath);
        auto fragCode = readFile(fragPath);

        std::cout << "VSCS: " << vertCode.size() << "\n";
        std::cout << "FSCS: " << fragCode.size() << "\n";
    }
}

