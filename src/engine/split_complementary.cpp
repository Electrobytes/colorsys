#include "engine.h"

namespace colorsys::engine {
    std::vector<std::vector<int>> split_complementary(const std::vector<int>& inputColor, int magnitude) {
        if (magnitude == 0) magnitude = 42;

        int complementaryColor = inputColor.at(0) + 180;

        std::vector<std::vector<int>> result(2, inputColor);
        result.at(0).at(0) = complementaryColor - magnitude;
        result.at(1).at(0) = complementaryColor + magnitude;

        for (std::vector<int>& vec : result) {
            vec.at(0) = (vec.at(0) % 360 + 360) % 360;
        }

        return result;

    }
}