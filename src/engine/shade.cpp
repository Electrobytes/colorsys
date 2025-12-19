#include "engine.h"

namespace colorsys::engine {
    std::vector<std::vector<int>> shade(const std::vector<int>& inputColor, int magnitude) {
        if (magnitude == 0) magnitude = 5;

        std::vector<std::vector<int>> outputColors = {inputColor};

        outputColors.at(0).at(2) -= magnitude;

        return outputColors;
    }
}