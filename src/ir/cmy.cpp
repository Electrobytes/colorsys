#include "intermediate.h"
#include <vector>
#include <cmath>

namespace colorsys::intermediate {
    namespace from {
        void cmy(std::vector<int>& convert) {
            for (int& color : convert) color = static_cast<int>(255.0 * (1.0 - (static_cast<float>(color) / 100.0)));

            colorsys::intermediate::from::rgb(convert);
        }
    }

    namespace to {
        void cmy(std::vector<int>& convert) {
            colorsys::intermediate::to::rgb(convert);

            for (int& color : convert) color = static_cast<int>(100 * (1.0 - (static_cast<float>(color) / 255.0)));
        }
    }
}