#pragma once

#include <vector>
#include <array>
#include <iterator>
#include <memory>
#include "tokenize.h"

namespace colorsys {

    struct ColorSettings {
        colorsys::modeRef selectedMode;
        colorsys::typeRef inputModel;
        colorsys::typeRef outputModel;
        int functionMagnitude;
        int outputRange;   

        static std::shared_ptr<ColorSettings> getConfig() {
            if (globalConfig == nullptr) {
                globalConfig = std::make_shared<ColorSettings>();
            }

            return globalConfig;
        }

        private:

        static std::shared_ptr<ColorSettings> globalConfig;
    };

    std::shared_ptr<ColorSettings> ColorSettings::globalConfig = nullptr;


}