#include "convert.h"

namespace colorsys::intermediate {
    namespace from {
        void hwb(std::vector<int>& convert) {
            convert.at(1) = 100 * (1 - convert.at(1) / (100 - convert.at(2)));
            convert.at(2) = 100 - convert.at(2); // 211, 99, 90
            colorsys::intermediate::from::hsv(convert);
        }
    }

    namespace to {
        void hwb(std::vector<int>& convert) {
            colorsys::intermediate::to::hsv(convert);
            convert.at(1) = convert.at(2) - (convert.at(1) * convert.at(2) / 100);  
            convert.at(2) = 100 - convert.at(2);
        }
    }
}

/**
 * Reference(s):
 * - https://alvyray.com/Papers/CG/HWB_JGTv208.pdf
 */
