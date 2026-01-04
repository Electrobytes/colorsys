#pragma once

#include <vector>
#include <algorithm>
#include <array>
#include "tokenize.h"


namespace colorsys {
    namespace engine {
        std::vector<std::vector<int>> complementary(const std::vector<int>& inputColor);
        std::vector<std::vector<int>> analogous(const std::vector<int>& inputColor, int magnitude);
        std::vector<std::vector<int>> shade(const std::vector<int>& inputColor, int magnitude, int range);
        std::vector<std::vector<int>> split_complementary(const std::vector<int>& inputColor, int magnitude);
        std::vector<std::vector<int>> square(const std::vector<int>& inputColor);
        std::vector<std::vector<int>> triadic(const std::vector<int>& inputColor);
        std::vector<std::vector<int>> tint(const std::vector<int>& inputColor, int magnitude, int range);
    }
    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues, const int& selectedMode, int magnitude, int range);
}
