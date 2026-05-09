#include <vector>
#include "convert.h"
#include "tokenize.h"

namespace colorsys {
    std::vector<int> toHsl(const std::vector<int>& origin) {
        colorsys::typeRef inputType = colorsys::ColorSettings::getConfig()->inputModel;
        std::vector<int> result = origin;
    

        switch (inputType) {
            case colorsys::t_rgb: // fallthrough
            case colorsys::t_hex:
                colorsys::intermediate::from::rgb(result);
                break;
            case colorsys::t_cmy:
                colorsys::intermediate::from::cmy(result);
                break;
            case colorsys::t_cmyk:
                colorsys::intermediate::from::cmyk(result);
                break;
            case colorsys::t_hsl:
                break; // Cuz hsl is the intermediate value
            case colorsys::t_hsv:
                colorsys::intermediate::from::hsv(result);
                break;
            case colorsys::t_hwb:
                colorsys::intermediate::from::hwb(result);
                break;
                
        }
        
        colorsys::DisplayableColor::getSingleton()->captureInput(result);
        return result;
    }

    void fromHsl(std::vector<std::vector<int>>& origin) {
        colorsys::typeRef outputType = colorsys::ColorSettings::getConfig()->outputModel;
        for (std::vector<int>& vec : origin) {
            switch (outputType) {
                case colorsys::t_rgb:
                case colorsys::t_hex:
                    colorsys::intermediate::to::rgb(vec);
                    break;
                case colorsys::t_cmy:
                    colorsys::intermediate::to::cmy(vec);
                    break;
                case colorsys::t_cmyk:
                    colorsys::intermediate::to::cmyk(vec);
                    break;
                case colorsys::t_hsl:
                    break; // Cuz the intermediate representation is already in hsl
                case colorsys::t_hsv:
                    colorsys::intermediate::to::hsv(vec);
                    break;
                case colorsys::t_hwb:
                    colorsys::intermediate::to::hwb(vec);
                    break;
            }
        } 

    }

        inline std::shared_ptr<DisplayableColor> DisplayableColor::getSingleton() {
            if (globalDisplay ==  nullptr) {
                globalDisplay = std::make_shared<DisplayableColor>();
            }

            return globalDisplay;
        }

        void DisplayableColor::captureInput(std::vector<int> hslInput) {
            commonCapture(this->displayableInput, hslInput);
        }

        void DisplayableColor::captureOutput(std::vector<int> hslOutput) {
            commonCapture(this->displayableInput, hslOutput);
        }

        ftxui::Color DisplayableColor::displayInput() {
            return displayableInput;
        }

        ftxui::Color DisplayableColor::displayOutput() {
            return displayableOutput;
        }


        void DisplayableColor::commonCapture(ftxui::Color& displayColor, std::vector<int>& hslVector) {
            colorsys::intermediate::to::rgb(hslVector);

            auto getElementbyEnum = [&hslVector](const colorPosition& index) -> int {
                return hslVector.at(static_cast<int>(index));
            };

            displayColor = ftxui::Color(
                getElementbyEnum(colorPosition::red),
                getElementbyEnum(colorPosition::green),
                getElementbyEnum(colorPosition::blue)
            );
        }
    inline std::shared_ptr<DisplayableColor> DisplayableColor::globalDisplay = {};

}
