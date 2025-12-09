#include <vector>
#include <cmath>

namespace colorsys::intermediate {
    namespace start {
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
    // TODO: rewrite whatever the hell is this
    namespace finish {
        void hsv(std::vector<int>& convert) {
            int lum = convert.at(2);
            convert.at(2) = lum + convert.at(1) * std::min(lum / 100, 1 - (lum / 100));
            convert.at(2) /= 100;

            if (convert.at(2) == 0) convert.at(1) = 0;
            else {
                convert.at(1) = 200 * (1 - (lum / convert.at(2)));
            }
        }
    }
}