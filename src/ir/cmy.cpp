#include "intermediate.h"
#include <vector>
#include <cmath>

namespace colorsys::intermediate {
    namespace start {
        void cmy(std::vector<int>& convert) {
            for (int& color : convert) color = static_cast<int>(255.0 * (1.0 - (static_cast<float>(color) / 100.0)));

            colorsys::intermediate::start::rgb(convert);
        }
    }

    namespace finish {
        void cmy(std::vector<int>& convert) {
            colorsys::intermediate::finish::rgb(convert);

            for (int& color : convert) color = static_cast<int>(100 * (1.0 - (static_cast<float>(color) / 255.0)));
        }
    }
}