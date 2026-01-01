#include "engine.h"

namespace colorsys {

    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues, const int& selectedMode, int magnitude, int range) {
        switch (selectedMode) {
            case colorsys::m_convert:
                return { intermediateValues };

            case colorsys::m_complementary:
                return engine::complementary(intermediateValues);

            case colorsys::m_split_complementary:
                return engine::split_complementary(intermediateValues, magnitude);
            
            case colorsys::m_analogous:
                return engine::analogous(intermediateValues, magnitude);
            
            
            case colorsys::m_shade:
                return engine::shade(intermediateValues, magnitude, range);

            case colorsys::m_tint:
                return engine::tint(intermediateValues, magnitude, range);
        }

        return {{420}}; // There's no color model/system that would reach number 420 so that's prolly a good placeholder for a while
    }
}