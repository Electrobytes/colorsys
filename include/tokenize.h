#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <format>
#include <cxxopts.hpp>

namespace colorsys {
    enum modeRef {
        m_convert = 0,
        m_analogous = 1,
        m_complementary = 2,
        m_split_complementary = 3,
        m_square = 4,
        m_triadic = 5,
        m_shade = 20,
        m_tint = 21
    };

    enum typeRef {
        t_rgb = 0,
        t_cmy = 1,
        t_hex = 2,
        t_hsl = 3,
        t_hsv = 4,
        t_cmyk = 5
    };

    namespace hashmaps {
        inline const std::unordered_map<std::string, int> modes = {
            {"convert", 0},
            {"analogous", 1},
            {"complementary", 2},
            {"split_complementary", 3},
            {"square", 4},
            {"triadic", 5},
            {"shade", 20},
            {"tint", 21}
        };

        inline const std::unordered_map<std::string, int> types = {
            {"rgb", 0},
            {"cmy", 1},
            {"hex", 2},
            {"hsl", 3},
            {"hsv", 4},
            {"cmyk", 5}
        };
    }

    // TODO: do heavy refactor with the return type
    inline std::vector<int> argumentTokenize(const cxxopts::ParseResult& argumentResults) { 
        std::vector<int> tokenizedResult {};
        std::array<std::string, 3> enteredValues {};
        enteredValues.at(0) = argumentResults["mode"].as<std::string>();
        enteredValues.at(1) = argumentResults["inputModel"].as<std::string>();
        enteredValues.at(2) = argumentResults["outputModel"].as<std::string>();
        int selector = 0;
        try {
            tokenizedResult.push_back(hashmaps::modes.at(enteredValues.at(selector)));
            selector++; // why?!?!?
            for (selector = 1; selector < enteredValues.size(); selector++);
                tokenizedResult.push_back(hashmaps::types.at(enteredValues.at(selector)));
        }
        catch (const std::out_of_range&) {
            std::string namedParameter {};
            switch (selector) {
                case 0: 
                    namedParameter = "function/mode";
                    break;
                case 1: 
                    namedParameter = "input type";
                    break;
                case 2:
                    namedParameter = "output type";
                    break;
                default:
                    namedParameter = "unknown parameter";
                    break;
            }

            throw std::invalid_argument(std::format("The {} \"{}\" does not exist, maybe a possible type?", namedParameter, enteredValues.at(selector)));
        }


        return tokenizedResult;
    }


}