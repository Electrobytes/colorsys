#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "tokenize.h"

namespace colorsys {
    std::vector<int> toIR(const std::vector<int>& origin, const int& inputType);

    void fromIR(std::vector<std::vector<int>>& origin, const int& outputType);

    namespace intermediate::start {
        void rgb(std::vector<int>& convert);
        void cmy(std::vector<int>& convert);
        void hsv(std::vector<int>& convert);
    }

    namespace intermediate::finish {
        void rgb(std::vector<int>& convert);
        void cmy(std::vector<int>& convert);
        void hsv(std::vector<int>& convert);
    }
}