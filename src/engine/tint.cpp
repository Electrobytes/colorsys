#include "engine.h"

namespace colorsys::engine {
    std::vector<std::vector<int>> tint(const std::vector<int>& inputColor, int magnitude, int range) {
        if (magnitude == 0) magnitude = 42;

        std::vector<std::vector<int>> outputColors {};
        for (int i = 1; i <= range; i++) {
            outputColors.push_back(inputColor);
            outputColors.at(i-1).at(2) += magnitude * i;
        }

        return outputColors;
    }
}