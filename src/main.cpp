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
    cxxopts::ParseResult argumentResult {};
    if (auto functionStatus = colorsys::programOptions(argc, argv); functionStatus) {
        argumentResult = *functionStatus;
    } else {
        std::cout << "[-] Error occured while parsing arguments. Now signaling for a program exit. \n";
        return 301;
    }

    // Tokenize
    std::vector<int> argumentTokens {}; // mode, inputModel, outputModel
    if (auto functionStatus = colorsys::argumentTokenize(argumentResult); functionStatus) {
        argumentTokens = *functionStatus;
    } else {
        std::cout << "[-] Error occured while hashing values. Now signaling for a program exit.\n";
        return 302;
    }

    // sanity check
    // Needs heavy rewrite for cleaner and tolerable codebase
    std::vector<int> inputColor {};
    if (auto functionStatus = colorsys::inputSanity(argumentResult["input"].as<std::string>(), argumentTokens.at(1)); functionStatus) {
        inputColor = *functionStatus;
    } else {
        std::cout << "[-] Sanity check failed. Please check your \"input\" argument and -i flag if they are correct. Now signaling for a program exit.\n";
        return 303;
    }
    
    std::vector<int> irColor = colorsys::toIR(inputColor, argumentTokens[1]);
    int functionMagnitude = argumentResult["magnitude"].as<int>();
    int functionOutputRange = argumentResult["range"].as<int>();
    std::vector<std::vector<int>> outputColor = colorsys::engineHandler(irColor, argumentTokens[0], functionMagnitude, functionOutputRange);
    colorsys::fromIR(outputColor, argumentTokens[2]);
    colorsys::print(inputColor, outputColor, argumentTokens);
    
    if (argumentResult["debug"].as<bool>()) {
        std::cout // [0]
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
  * Info:
  * [0]: Debug
  */
