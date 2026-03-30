#include "intermediate.h"

namespace colorsys::intermediate {
    namespace start {
        void hwb(std::vector<int>& convert) {
            convert.at(1) = NULL; // TODO: formula
            convert.at(2) = 1 - convert.at(2);
            colorsys::intermediate::start::hsv(convert);



        }
    }

    namespace finish {
        void hwb(std::vector<int>& convert) {
            // TODO: formula
        }
    }
}