#include "engine.h"
#include <stdexcept>

namespace colorsys {

    std::vector<std::vector<int>> engineHandler(const std::vector<int>& intermediateValues) {
        auto globalConfig = colorsys::ColorSettings::getConfig();

        switch (globalConfig->selectedMode) {
            case colorsys::m_convert:
                return { intermediateValues };

            case colorsys::m_complementary:
                return engine::complementary(intermediateValues);

            case colorsys::m_split_complementary:
                return engine::split_complementary(intermediateValues, globalConfig->functionMagnitude);
            
            case colorsys::m_analogous:
                return engine::analogous(intermediateValues, globalConfig->functionMagnitude);
            
            case colorsys::m_square:
                return engine::square(intermediateValues);

            case colorsys::m_triadic:
                return engine::triadic(intermediateValues);
            
            case colorsys::m_shade:
                return engine::shade(intermediateValues, globalConfig->functionMagnitude, globalConfig->outputRange);

            case colorsys::m_tint:
                return engine::tint(intermediateValues, globalConfig->functionMagnitude, globalConfig->outputRange);
            case colorsys::m_warmer:
                globalConfig->functionMagnitude *= -1;
            case colorsys::m_colder:
            case colorsys::m_temperature:
                return engine::temperature(intermediateValues, globalConfig->functionMagnitude, globalConfig->outputRange);

            case colorsys::m_tetradic:
                return engine::tetradic(intermediateValues, globalConfig->functionMagnitude);
        }

        std::cerr << "The function used is not yet implemented :(\n";
        std::exit(303);
    }
}
