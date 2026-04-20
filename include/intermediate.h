#pragma once

#include <vector>
#include <string>
#include <algorithm>
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
}