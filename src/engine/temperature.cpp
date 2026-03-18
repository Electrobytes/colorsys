#include "engine.h"
#include <algorithm>
#include <cmath>

namespace colorsys::engine {
    std::vector<std::vector<int>> temperature(const std::vector<int>& inputColor, int magnitude, int range) {
        std::vector<std::vector<int>> result {};
        bool toWarmer = magnitude < 0;
        magnitude = std::abs(magnitude);
        const int hottestHue = 0, coldestHue = 240;
        float incrementHue {};
        if (toWarmer) {
            incrementHue = inputColor.at(0) * -1;
            if (inputColor.at(0) >= 180) incrementHue += 360;
            incrementHue *= magnitude / 100.0;
        } else {
            incrementHue = (coldestHue - inputColor.at(0)) / 100.0 * magnitude;
        }

        incrementHue = std::floor(incrementHue);

        for (int i = 0; i < range; i++) {
            result.push_back(inputColor);
            result.at(i).at(0) += incrementHue * (i+1);
        }

        return result;
    }
}