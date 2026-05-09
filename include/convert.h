#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <ftxui/screen/color.hpp>
#include "tokenize.h"

namespace colorsys {
    std::vector<int> toHsl(const std::vector<int>& origin);

    void fromHsl(std::vector<std::vector<int>>& origin);

    namespace intermediate::from {
        void rgb(std::vector<int>& convert);
        void cmy(std::vector<int>& convert);
        void cmyk(std::vector<int>& convert);
        void hsv(std::vector<int>& convert);
        void hwb(std::vector<int>& convert);
    }

    namespace intermediate::to {
        void rgb(std::vector<int>& convert);
        void cmy(std::vector<int>& convert);
        void cmyk(std::vector<int>& convert);
        void hsv(std::vector<int>& convert);
        void hwb(std::vector<int>& convert);
    }

    struct DisplayableColor {

        inline static std::shared_ptr<DisplayableColor> getSingleton();

        void captureInput(std::vector<int> hslInput);

        void captureOutput(std::vector<int> hslOutput);

        ftxui::Color displayInput();

        ftxui::Color displayOutput();

        private:

        enum class colorPosition : int {
            red = 0,
            green,
            blue
        };

        void commonCapture(ftxui::Color& displayColor, std::vector<int>& hslVector);

        ftxui::Color displayableInput;
        ftxui::Color displayableOutput;

        static std::shared_ptr<DisplayableColor> globalDisplay;
    };

}
