#include "engine.h"

namespace colorsys::engine {
    std::vector<std::vector<int>> triadic(const std::vector<int>& inputColor) {

        std::vector<std::vector<int>> outputColors {};
        for (int i = 0; i < 3; i++) {
            outputColors.push_back(inputColor);
            outputColors.at(i).at(0) += 120 * i;
            outputColors.at(i).at(0) %= 360;
        }

        return outputColors;
    }
}