#include "convert.h"

namespace colorsys::intermediate {
    namespace from {
        void cmyk(std::vector<int>& convert) {
            if (convert.at(3) <= 0) return;
            const float colorMultiplier = 100.0 / convert.at(3);
            convert.pop_back();
            for (int& color : convert) color = (color + 100) / colorMultiplier;

            colorsys::intermediate::from::cmy(convert);
        }
    }

    namespace to {
        void cmyk(std::vector<int>& convert) {
            colorsys::intermediate::to::cmy(convert);

            convert.push_back(0); // key; its the same thing basically, but it needs an actual formula.
        }
    }
}
