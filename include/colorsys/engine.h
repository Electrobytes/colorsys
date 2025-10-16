#pragma once

#include <vector>
#include <algorithm>
#include <array>
#include "tokenize.h"


namespace colorsys {
    namespace engine {
        std::vector<std::vector<int>> complementary(const std::vector<int>& inputColor) {
            std::array<int, 3> result;

            result.at(0) = inputColor.at(0) + 180;
            result.at(1) = inputColor.at(1);
            result.at(2) = inputColor.at(2);

            // rotation simplification
            std::array<int, 3>::iterator hue = result.begin();
            int rotationCase = *hue % 360;
            if (rotationCase != *hue) { // if its more than or equal to 360, then simplify
                *hue = rotationCase;
            }

            return { std::vector<int>(result.begin(), result.end()) };

        }
    }

    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues, const int& selectedMode) {
        switch (selectedMode) {
            case colorsys::m_convert:
                return { intermediateValues };

            case colorsys::m_complementary:
                return engine::complementary(intermediateValues);
        }

        return {{420}}; // There's no color model/system that would reach number 420 so that's prolly a good placeholder for a while
    }
}
