#include "engine.h"
#include <algorithm>
#include <cmath>

namespace colorsys::engine {
    std::vector<std::vector<int>> analogous(const std::vector<int>& inputColor, int magnitude) {
        std::vector<std::vector<int>> result(2, inputColor);
        if (magnitude == 0) magnitude = 42;
        
        result.at(0).at(0) -= magnitude;
        result.at(1).at(0) += magnitude;

        for (std::vector<int>& vec : result) {
            vec.at(0) = (vec.at(0) % 360 + 360) % 360;
        }

        return result;

    }
}