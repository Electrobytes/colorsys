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
#include "intermediate.h"
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
    int functionMagnitude = argumentResult["magnitude"].as<int>();
    int functionRange = argumentResult["range"].as<int>();
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


/**
 * Checklist:
 * Color mixing model converter [x]
 *      RGB
 *      CMY
 *      Hex
 * Color Harmonies [x]
 *      Analogous
 *      Complementary
 * Color Variation Chart [x]
 */

/**
 * Process
 * input [/] -> parse [/] -> tokenize arguments [/] -> sanity checks [1] -> convert model to intermediate [1] -> function* [1] -> convert intermediate to model [1] -> output [1]
 * 
 * *convert function simple skips that
 * **another sanity check will apply here
 * 1: bare minimum implementation
 */

 /**
  * Error Codes:
  * 301: Parsing issue
  * 302: Unrecognized mode/function
  * 
  */
