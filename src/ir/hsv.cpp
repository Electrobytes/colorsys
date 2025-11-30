#include <vector>
#include <cmath>

// broken af
namespace colorsys::intermediate {
    namespace start {
        void hsv(std::vector<int>& convert) {
            int value = convert.at(2);
            convert.at(2) = (200 * value) - (convert.at(1) * value);
            convert.at(2) /= 20000;
            if ((convert.at(2) == 0) || (convert.at(2) == 100)) convert.at(1) = 0;
            else {
                float lumDecimal = convert.at(2) / 100;
                convert.at(1) = value - convert.at(2);
                convert.at(1) /= 100 * std::min(lumDecimal, 1 - lumDecimal);
            }
        }
    }

    namespace finish {
        void hsv(std::vector<int>& convert) {
            convert.at(2) = 100 * (convert.at(2) + (convert.at(1) * std::min(100 * convert.at(2), 1 - 100 * convert.at(2))));
        }
    }
}