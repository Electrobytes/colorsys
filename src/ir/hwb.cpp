#include "intermediate.h"

// TODO: fix possible rounding issue here
namespace colorsys::intermediate {
    namespace start {
        void hwb(std::vector<int>& convert) {
            convert.at(1) = 100 * (1 - convert.at(1) / (100 - convert.at(2)));
            convert.at(2) -= 100;
            colorsys::intermediate::start::hsv(convert);
        }
    }

    namespace finish {
        void hwb(std::vector<int>& convert) {
            colorsys::intermediate::finish::hsv(convert);
            convert.at(1) = convert.at(2) - (convert.at(1) * convert.at(2) / 10);
            convert.at(2) -= 100;
        }
    }
}

/**
 * Reference(s):
 * - https://alvyray.com/Papers/CG/HWB_JGTv208.pdf
 */