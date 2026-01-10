#include "intermediate.h"

namespace colorsys::intermediate {
    namespace start {
        void cmyk(std::vector<int>& convert) {
            if (convert.at(3) <= 0) return;
            const float colorMultiplier = 100.0 / convert.at(3);
            convert.pop_back();
            for (int& color : convert) color = (color + 100) / colorMultiplier;

            colorsys::intermediate::start::cmy(convert);
        }
    }

    namespace finish {
        void cmyk(std::vector<int>& convert) {
            colorsys::intermediate::finish::cmy(convert);

            convert.push_back(0); // key; its the same thing basically, but it needs an actual formula.
        }
    }
}