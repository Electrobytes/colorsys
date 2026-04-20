#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <format>
#include <cstdlib>
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
        m_tint = 21,
        m_temperature = 22,
        m_colder = 220,
        m_warmer = 221
    };

    enum typeRef {
        t_rgb = 0,
        t_cmy = 1,
        t_hex = 2,
        t_hsl = 3,
        t_hsv = 4,
        t_cmyk = 5,
        t_hwb = 6
    };

    namespace hashmaps {
        inline const std::unordered_map<std::string, int> modes = {
            {"convert", m_convert},
            {"analogous", m_analogous},
            {"complementary", m_complementary},
            {"split_complementary", m_split_complementary},
            {"square", m_square},
            {"triadic", m_triadic},
            {"shade", m_shade},
            {"tint", m_tint},
            {"temp", m_temperature},
            {"temperature", m_temperature},
            {"colder", m_colder},
            {"warmer", m_warmer}
        };

        inline const std::unordered_map<std::string, int> types = {
            {"rgb", t_rgb},
            {"cmy", t_cmy},
            {"hex", t_hex},
            {"hsl", t_hsl},
            {"hsv", t_hsv},
            {"cmyk", t_cmyk},
            {"hwb", t_hwb}
        };
    }

    struct ColorSettings {
        colorsys::modeRef selectedMode;
        colorsys::typeRef inputModel;
        colorsys::typeRef outputModel;
        int functionMagnitude;
        int outputRange;   

        inline static std::shared_ptr<ColorSettings> getConfig() {
            if (globalConfig == nullptr) {
                globalConfig = std::make_shared<ColorSettings>();
            }

            return globalConfig;
        }

        private:

        static std::shared_ptr<ColorSettings> globalConfig;
    };

    inline std::shared_ptr<ColorSettings> ColorSettings::globalConfig = nullptr;

    // TODO: do heavy refactor with the return type
    inline void argumentTokenize(const cxxopts::ParseResult& argumentResults) { 
        std::vector<int> tokenizedResult {};
        
        std::array<std::string, 3> enteredValues {};
        enteredValues.at(0) = argumentResults["mode"].as<std::string>();
        enteredValues.at(1) = argumentResults["inputModel"].as<std::string>();
        enteredValues.at(2) = argumentResults["outputModel"].as<std::string>();
        int selector = 0;
        try {
            /*
            tokenizedResult.push_back(hashmaps::modes.at(enteredValues.at(selector)));
            selector++; // why?!?!? // Seemed to have an issue here but haven't tested it
            for (selector = 1; selector < enteredValues.size(); selector++);
                tokenizedResult.push_back(hashmaps::types.at(enteredValues.at(selector)));
            */
            for (; selector < enteredValues.size(); selector++) {
                if (!selector) tokenizedResult.push_back(hashmaps::modes.at(enteredValues.at(selector)));
                else tokenizedResult.push_back(hashmaps::types.at(enteredValues.at(selector)));
            }
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

            std::cerr << std::format("The {} \"{}\" does not exist, maybe a possible type?\n", namedParameter, enteredValues.at(selector));
            std::exit(301);
        }

        auto configResult = colorsys::ColorSettings::getConfig();
        configResult->selectedMode = modeRef(tokenizedResult.at(0));
        configResult->inputModel = typeRef(tokenizedResult.at(1));
        configResult->outputModel = typeRef(tokenizedResult.at(2));

    }


}