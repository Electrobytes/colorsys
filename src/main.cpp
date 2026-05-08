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
#include "conversion.h"
#include "engine.h"
#include "print.h"

int main(int argc, char** argv) {

    // Parser
    cxxopts::ParseResult argumentResult  = colorsys::programOptions(argc, argv);

    // Tokenize
    colorsys::argumentTokenize(argumentResult); // mode, inputModel, outputModel

    // Sanity check
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
