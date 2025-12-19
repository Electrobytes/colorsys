#include <string>
#include <vector>
#include <array>
#include <utility>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "tokenize.h"

namespace colorsys {
    namespace {
        std::string adaptiveFormat(const std::vector<int>& toFormat, const int& toType) {
            std::string hexcode = "#";

            switch (toType) {
                case colorsys::t_hex:
                    for (const int& i : toFormat) {
                        hexcode += fmt::format("{:02x}", i);
                    }

                    return hexcode;
                    
                default:
                    return fmt::format("{:n}", toFormat);
            }
        }
    }

    void print(const std::vector<int>& inputColor, const std::vector<std::vector<int>>& outputColor, const std::vector<int>& tokens) {
        std::array<std::string, 3> metadata {}; // mode, inputType, outputType
        for (const auto& [mode, value] : hashmaps::modes) {
            if (value != tokens.at(0)) continue;
            metadata.at(0) = mode;
        }

        for (const auto& [type, value] : hashmaps::types) {
            if (value == tokens.at(1)) metadata.at(1) = type;
            if (value == tokens.at(2)) metadata.at(2) = type;
        }

        std::array<ftxui::Element, 5> formattedMetadata {};
        ftxui::Elements formattedOutputColor {};

        
        for (const std::vector<int>& vectorIterator : outputColor) {
            formattedOutputColor.push_back(ftxui::text(adaptiveFormat(vectorIterator, tokens.at(2))) | ftxui::border);
        }

        formattedMetadata.at(0) = ftxui::text(metadata.at(0)); // Mode name
        formattedMetadata.at(1) = ftxui::text(adaptiveFormat(inputColor, tokens.at(1)));
        formattedMetadata.at(2) = ftxui::hbox(formattedOutputColor);
        formattedMetadata.at(3) = ftxui::text(metadata.at(1));
        formattedMetadata.at(4) = ftxui::text(metadata.at(2));

        /*
        ftxui::Element document = ftxui::vbox({
            ftxui::window(ftxui::text("Input"), formattedMetadata.at(1)),
            ftxui::window(ftxui::text("Function/Mode"), formattedMetadata.at(0)),
            ftxui::window(ftxui::text("Output/s"), formattedMetadata.at(2)),
            ftxui::window(ftxui::text("I/O types"), ftxui::hbox({
               ftxui::window(ftxui::text("Input type"), formattedMetadata.at(3)),
               ftxui::window(ftxui::text("Output type"), formattedMetadata.at(4)) 
            }))
        });
        */

        ftxui::Element document = ftxui::gridbox({
            {ftxui::window(ftxui::text("Input"), formattedMetadata.at(1))},
            {ftxui::window(ftxui::text("Function/Mode"), formattedMetadata.at(0))},
            {ftxui::window(ftxui::text("Output/s"), formattedMetadata.at(2))},
            {ftxui::window(ftxui::text("I/O types"), ftxui::hbox({
                ftxui::window(ftxui::text("Input type"), formattedMetadata.at(3)),
                ftxui::window(ftxui::text("Output type"), formattedMetadata.at(4))
            }))}
        });

        ftxui::Screen printer = ftxui::Screen::Create(ftxui::Dimension::Fit(document), ftxui::Dimension::Fit(document, true));
        ftxui::Render(printer, document);
        printer.Print();

        
    }
}