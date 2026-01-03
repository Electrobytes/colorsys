#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <cxxopts.hpp>

namespace colorsys {
    enum modeRef {
        m_convert = 0,
        m_analogous = 1,
        m_complementary = 2,
        m_split_complementary = 3,
        m_square = 4,
        m_shade = 20,
        m_tint = 21
    };

    enum typeRef {
        t_rgb = 0,
        t_cmy = 1,
        t_hex = 2,
        t_hsl = 3,
        t_hsv = 4
    };

    namespace hashmaps {
        inline const std::unordered_map<std::string, int> modes = {
            {"convert", 0},
            {"analogous", 1},
            {"complementary", 2},
            {"split_complementary", 3},
            {"square", 4},
            {"shade", 20},
            {"tint", 21}
        };

        inline const std::unordered_map<std::string, int> types = {
            {"rgb", 0},
            {"cmy", 1},
            {"hex", 2},
            {"hsl", 3},
            {"hsv", 4}
        };
    }

    inline std::optional<std::vector<int>> argumentTokenize(const cxxopts::ParseResult& argumentResults) {
        std::vector<int> result {};

        try {
            result = {
                hashmaps::modes.at(argumentResults["mode"].as<std::string>()),
                hashmaps::types.at(argumentResults["inputModel"].as<std::string>()),
                hashmaps::types.at(argumentResults["outputModel"].as<std::string>())
            };

        } catch (const std::exception& caughtException) {
            return std::nullopt;
        }

        return result;
    }


}