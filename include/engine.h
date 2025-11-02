#pragma once

#include <vector>
#include <algorithm>
#include <array>
#include "tokenize.h"


namespace colorsys {
    namespace engine {
        std::vector<std::vector<int>> complementary(const std::vector<int>& inputColor);
    }
    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues, const int& selectedMode, int magnitude);
}
