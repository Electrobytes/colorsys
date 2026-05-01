#include "engine.h"
#include <iterator>

namespace colorsys::engine {
    std::vector<std::vector<int>> tetradic(const std::vector<int>& inputColor, int magnitude) {
        if (magnitude == 0) magnitude = 42;
        std::vector<std::vector<int>> result {};
/*
        result.push_back(inputColor);

        result.push_back(inputColor);
        result.at(1).at(0) += 180;
        result.at(1).at(0) %= 360;

        result.push_back(inputColor);
        result.at(2).at(0) += magnitude;
        result.at(2).at(0) %= 360;

        result.push_back(*std::prev(result.end()));
        result.at(3).at(0) += 180;
        result.at(3).at(0) %= 360;
*/
        for (int i = 0; i < 4; i++) {
            result.push_back((i != 3) ? inputColor : *std::prev(result.end()));
            if (i == 2) result.at(i).at(0) += magnitude;
            else if (i % 2) result.at(i).at(0) += 180;
            result.at(i).at(0) %= 360;
        }

        return result;
    }
}
