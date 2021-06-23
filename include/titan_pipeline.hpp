#pragma once

#include <string>
#include <vector>

namespace titan
{
    class TitanPipeline
    {
    public:
        TitanPipeline(const std::string &vertFilePath, const std::string &fragFilePath);

    private:
        static std::vector<char> readFile(const std::string &filepath);

        void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath);
    };
} // namespace titan
