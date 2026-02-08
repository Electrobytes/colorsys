#include "engine.h"

namespace colorsys::engine {
    std::vector<std::vector<int>> temperature(const std::vector<int>& inputColor, int magnitude, int range) {
        const std::vector<int> hottestColor = {14, 100, 50};
        const std::vector<int> coldestColor = {224, 100, 80};
        std::vector<int> incrementColor {};
        std::vector<std::vector<int>> result {};
        bool toWarmer = magnitude > 0;
        std::abs(magnitude);

        for (int i = 0; i < 3; i++) {
            incrementColor.push_back((inputColor.at(i) - (toWarmer) ? hottestColor.at(i) : coldestColor.at(i)) / magnitude);
        }     

        for (int i = 0; i < range; i++) {
            result.push_back(inputColor);
            for (int j = 0; j < 3; j++) result.at(i).at(j) += incrementColor.at(j) * (i+1);
        }

        return result;
    }
}