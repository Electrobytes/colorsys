#pragma once

#include <vector>
#include <string>
#include <optional>
#include <regex>
#include <algorithm>


namespace colorsys {
    std::optional<std::vector<int>> inputSanity(std::string colorInput, const int& inputType) {
        
        colorInput.erase(std::remove(colorInput.begin(), colorInput.end(), ' '), colorInput.end()); // Time complexity: 2n, cuz it iterates twice
        for (int i = 0; i < colorInput.size(); i++) {
            colorInput.at(i) = std::tolower(colorInput.at(i));
        }

        std::regex pattern("");
        std::smatch matcher {};
        
        switch (inputType) { 
            
            case colorsys::t_hex:
                pattern = "(?:(?:0x|#)?)((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2})((?:[0-9]|[a-f]){2})";
                break;

            default:
                pattern = "([0-9]{1,3})(?:,)([0-9]{1,3})(?:,)([0-9]{1,3})";
                break;


        }

        if (bool sanityStatus = std::regex_match(colorInput, matcher, pattern); !sanityStatus) {
            return std::nullopt;
            
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