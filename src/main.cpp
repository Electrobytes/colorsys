#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <algorithm>
#include <cxxopts.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "options.h"
#include "tokenize.h"
#include "sanity.h"
#include "convert.h"
#include "engine.h"
#include "print.h"

int main(int argc, char** argv) {

    cxxopts::ParseResult argumentResult  = colorsys::programOptions(argc, argv);


    std::vector<int> inputColor = colorsys::inputSanity(argumentResult["input"].as<std::string>());
    
    std::vector<int> ColorIr = colorsys::toHsl(inputColor);
    std::vector<std::vector<int>> outputColor = colorsys::engineHandler(ColorIr);
    colorsys::fromHsl(outputColor);
    colorsys::print(inputColor, outputColor);
    
    if (argumentResult["debug"].as<bool>()) {
        std::cout // Debug
            << "\nmode = " << argumentResult["mode"].as<std::string>()
            << "\ninput = " << argumentResult["input"].as<std::string>()
            << "\nmagnitude = " << argumentResult["magnitude"].as<int>()
            << "\ni = " << argumentResult["inputModel"].as<std::string>()
            << "\no = " << argumentResult["outputModel"].as<std::string>()
            << std::endl;
    }

    return 0;
}
