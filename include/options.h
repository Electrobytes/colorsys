#pragma once

#include <iostream>
#include <optional>
#include <cxxopts.hpp>

namespace colorsys {
    cxxopts::ParseResult programOptions(int& argc, char**& argv) {
        cxxopts::Options programFlags("colorsys", "Color Theory in the cmd!");

        programFlags.add_options()
            ("mode", "Choose what to do with the input.", cxxopts::value<std::string>())
            ("input", "Color input.", cxxopts::value<std::string>());

        programFlags.add_options("Color model")
            ("i,inputModel", "Color mixing model of the input. (Required)", cxxopts::value<std::string>())
            ("o,outputModel", "Color mixing model for the output. Default value is matched to the -i,--inputModel flag, but using the \"convert\" function will make this flag the basis for the output.", cxxopts::value<std::string>());

        programFlags.add_options("Fine-tuning")
            ("m,magnitude", "The intensity/magnitude of results", cxxopts::value<int>()->default_value("0"))
            ("r,range", "The number of outputs to be displayed. Not all functions support this.", cxxopts::value<int>()->default_value("1"));
            
        programFlags.add_options("Additional")
            
            ("h,help", "Prints the help message and exits.", cxxopts::value<std::string>()->default_value("none"))
            ("d,debug", "Show unformatted results for debugging.", cxxopts::value<bool>());

        programFlags.parse_positional({"mode", "input"});

        cxxopts::ParseResult result = programFlags.parse(argc, argv);

        if (result["help"].as<std::string>() == "none") return result;
        
        const std::string_view selectedHelpPage = result["help"].as<std::string>();
        if (selectedHelpPage == "general") std::cout << programFlags.help() << '\n';        
        std::exit(0);
        
    }
}
