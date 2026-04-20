#include <string>
#include <vector>
#include <array>
#include <utility>
#include <unordered_map>
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

    void print(const std::vector<int>& inputColor, const std::vector<std::vector<int>>& outputColor) {
        auto globalConfig = colorsys::ColorSettings::getConfig();
        std::array<std::string, 3> metadata {}; // mode, inputType, outputType
        for (const auto& [mode, value] : hashmaps::modes) {
            if (value != globalConfig->selectedMode) continue;
            metadata.at(0) = mode;
        }

        for (const auto& [type, value] : hashmaps::types) {
            if (value == globalConfig->inputModel) metadata.at(1) = type;
            if (value == globalConfig->outputModel) metadata.at(2) = type;
        }

        ftxui::Elements formattedOutputColor {};

        
        for (const std::vector<int>& vectorIterator : outputColor) {;
            std::vector<int> outputDisplay(vectorIterator);
            colorsys::intermediate::to::rgb(outputDisplay);
            formattedOutputColor.push_back(ftxui::vbox({
                ftxui::text(adaptiveFormat(vectorIterator, globalConfig->outputModel)) | ftxui::border,
                ftxui::text(" ") | ftxui::bgcolor(ftxui::Color::RGB(outputDisplay[0], outputDisplay[1], outputDisplay[2])) | ftxui::border
            }));
        }

        std::unordered_map<std::string_view, ftxui::Element> formattedMetadata {};
        formattedMetadata["function"] = ftxui::text(metadata.at(0));
        formattedMetadata["inputColor"] = ftxui::text(adaptiveFormat(inputColor, globalConfig->inputModel));
        // formattedMetadata["inputPreview"] = ftxui::paragraph(" ") | ftxui::bgcolor()
        formattedMetadata["outputColor"] = ftxui::hbox(formattedOutputColor);
        formattedMetadata["inputType"] = ftxui::text(metadata.at(1));
        formattedMetadata["outputType"] = ftxui::text(metadata.at(2));

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
            {
                ftxui::gridbox({
                    {ftxui::window(ftxui::text("Input"), formattedMetadata["inputColor"])},
                    {ftxui::window(ftxui::text("Function/Mode"), formattedMetadata["function"])}
                }),
                // ftxui::window(ftxui::text("Preview"), ftxui::text("Input (placeholder)"))
            },
                {ftxui::window(ftxui::text("Output(s)"), formattedMetadata["outputColor"])},
                {ftxui::window(ftxui::text("Types"), ftxui::hbox({
                    ftxui::window(ftxui::text("Input"), formattedMetadata["inputType"]),
                    ftxui::window(ftxui::text("Output"), formattedMetadata["outputType"])
                }))},
        });

        ftxui::Screen printer = ftxui::Screen::Create(ftxui::Dimension::Fit(document), ftxui::Dimension::Fit(document, true));
        ftxui::Render(printer, document);
        printer.Print();

        
    }
}
