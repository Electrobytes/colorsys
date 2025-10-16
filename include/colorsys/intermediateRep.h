#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "intermediateConv.h"
#include "tokenize.h"

namespace colorsys {
    std::vector<int> toIR(const std::vector<int>& origin, const int& inputType) {
        std::vector<int> result = origin;
    

        switch (inputType) {
            case colorsys::t_rgb: // fallthrough
            case colorsys::t_hex:
                colorsys::intermediate::start::rgb(result);
                break;
            case colorsys::t_hsl:
                break; // Cuz hsl is the intermediate value
                
        }

        return result;
    }

    void fromIR(std::vector<std::vector<int>>& origin, const int& outputType) {
        for (std::vector<int>& vec : origin) {
            switch (outputType) {
                case colorsys::t_rgb:
                case colorsys::t_hex:
                    colorsys::intermediate::finish::rgb(vec);
                case colorsys::t_hsl:
                    break; // Cuz the intermediate representation is already in hsl

            }
        }

    }
}