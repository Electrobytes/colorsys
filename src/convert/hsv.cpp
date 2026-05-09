#include "convert.h"
#include <vector>
#include <cmath>

namespace colorsys::intermediate {
    namespace from {
        void hsv(std::vector<int>& convert) {
            int value = convert.at(2);
            convert.at(2) = (200 * value) - (convert.at(1) * value);
            convert.at(2) /= 200;
            if ((convert.at(2) == 0) || (convert.at(2) == 100)) convert.at(1) = 0;
            else {
                /* this was a supposed fix
                convert.at(1) = value - convert.at(2);
                convert.at(1) /= std::min(convert.at(2) / 100, (100 - convert.at(2)) / 100);
                */
                float valueDec = value / 100.0;
                float luminDec = convert.at(2) / 100.0;

                convert.at(1) = 100 * ((valueDec - luminDec) / std::min(luminDec, 1 - luminDec));
            }
        }
    }
    namespace to {
        void hsv(std::vector<int>& convert) {
            int lum = convert.at(2);
            convert.at(2) = lum + convert.at(1) * std::min(lum / 100.0, 1 - (lum / 100.0));

            if (convert.at(2) == 0) convert.at(1) = 0;
            else {
                convert.at(1) = 200.0 * (1.0 - (static_cast<float>(lum) / static_cast<float>(convert.at(2))));
            }
        }
    }
}
