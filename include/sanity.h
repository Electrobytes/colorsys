#pragma once

#include <vector>
#include <string>
#include <optional>
#include <regex>
#include <algorithm>
#include "colorsys.h"


namespace colorsys {
    std::vector<int> inputSanity(std::string colorInput) {
        colorsys::typeRef inputType = colorsys::ColorSettings::getConfig()->inputModel;
        
        std::erase(colorInput, ' ');
        if (inputType == colorsys::t_hex) // skips the lowercase function if it's not a hex type
            for (char& letter : colorInput) letter = std::tolower(letter);

        std::regex pattern("");
        std::smatch matcher {};
        
        switch (inputType) { 
            
            case colorsys::t_hex:
                pattern = "(?:(?:0x|#)?)((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2})";
                break;

            case colorsys::t_cmyk:
                pattern = "([0-9]{1,3})(?:,)([0-9]{1,3})(?:,)([0-9]{1,3})(?:,)([0-9]{1,3})";
                break;

            default:
                pattern = "([0-9]{1,3})(?:,)([0-9]{1,3})(?:,)([0-9]{1,3})";
                break;


        }

        if (bool sanityStatus = std::regex_match(colorInput, matcher, pattern); !sanityStatus) {
            std::cerr << std::format("The input entered does not fit well with the expected format of the given type.\n");
            std::exit(302);
        }

        std::vector<std::string> captured(std::next(matcher.begin()), matcher.end());
        std::vector<int> result;

        for (const std::string& str : captured) {
            int base = (inputType == 2) ? 16 : 10;
            result.push_back(std::stoi(str, nullptr, base));
        }

        return result;
    }
}


/**
 * patterns
 * (-?[0-9]{1,3})(?:,)(-?[0-9]{1,3})(?:,)(-?[0-9]{1,3}) = for 3 signed valued models
 * (?[0-9]{1,3})(?:,)(?[0-9]{1,3})(?:,)(?[0-9]{1,3}) = for 3 unsigned valued models
 * (?:(?:0x|#)?)((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2}) = for hex
 * 
 */