#include "engine.h"

namespace colorsys {

    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues, const int& selectedMode, int magnitude) {
        switch (selectedMode) {
            case colorsys::m_convert:
                return { intermediateValues };

            case colorsys::m_complementary:
                return engine::complementary(intermediateValues);
            
            case colorsys::m_analogous:
                return engine::analogous(intermediateValues, magnitude);
        }

        return {{420}}; // There's no color model/system that would reach number 420 so that's prolly a good placeholder for a while
    }
}