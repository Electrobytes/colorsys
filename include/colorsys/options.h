#pragma once

#include <iostream>
#include <optional>
#include <cxxopts.hpp>

namespace colorsys {
    std::optional<cxxopts::ParseResult> programOptions(int& argc, char**& argv) {
        cxxopts::Options programFlags("colorsys", "Color Theory in the cmd!");

        programFlags.add_options("General arguments")
            ("mode", "Choose what to do with the input", cxxopts::value<std::string>())
            ("input", "Your color input", cxxopts::value<std::string>());

        programFlags.add_options("Additional options")
            ("i,inputModel", "Color mixing model of the input (Required)", cxxopts::value<std::string>())
            ("o,outputModel", "Color mixing model for the output. Default value is matched to the -i,--inputModel flag, but using the \"convert\" function will make this flag the basis for the output.", cxxopts::value<std::string>());

        programFlags.parse_positional({"mode", "input"});

        cxxopts::ParseResult result;
        try {
            result = programFlags.parse(argc, argv);
        } catch (const cxxopts::exceptions::exception& caughtException) {
            return std::nullopt;
        }

        return result;
        
    }
}