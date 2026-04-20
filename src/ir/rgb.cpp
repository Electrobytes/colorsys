#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

namespace colorsys::intermediate {
    namespace from {
        void rgb(std::vector<int>& convert) {
            std::vector<float> decimalRep(std::make_move_iterator(convert.begin()), std::make_move_iterator(convert.end()));
            convert.clear();

            float hue {}, sat {}, lum {};
            
            for (float& f : decimalRep) f /= 255.00;
            std::vector<float>::iterator maxElement = std::ranges::max_element(decimalRep);
            std::vector<float>::iterator minElement = std::ranges::min_element(decimalRep);
            float rangeDelta = *maxElement - *minElement;

            // Luminace
            lum = (*minElement + *maxElement) / 2;
            convert.insert(convert.begin(), std::lround(lum * 100));


            // Saturation
            if (rangeDelta == 0) sat = 0;
            else if (lum <= 0.5) sat = (*maxElement - *minElement) / (*maxElement + *minElement); 
            else if (lum > 0.5) sat = (*maxElement - *minElement) / (2.00 - *maxElement - *minElement);
            convert.insert(convert.begin(), std::lround(sat * 100));


            // Hue
            if (std::distance(decimalRep.begin(), maxElement) == 0) { 
                hue = std::fmod((decimalRep.at(1) - decimalRep.at(2)) / rangeDelta, 6); 
                // hue = 6.0 + std::fmod(hue, -6.0); // There are some situations where it would input negative numbers after division
            }
            else if (std::distance(decimalRep.begin(), maxElement) == 1) hue = 2.00 + (decimalRep.at(2) - decimalRep.at(0)) / rangeDelta;
            else if (std::distance(decimalRep.begin(), maxElement) == 2) hue = 4.00 + (decimalRep.at(0) - decimalRep.at(1)) / rangeDelta;
            convert.insert(convert.begin(), std::lround(hue * 60));

        }
    }

    namespace to {
        void rgb(std::vector<int>& convert) { 
            
            
            float chroma = (1.00 - std::abs((convert.at(2) / 50.00) - 1.00)) * convert.at(1);
            chroma /= 100.00;

            float hueDecimal = convert.at(0) / 60.00;

            float secondChroma = 1.00 - std::abs(std::fmod(hueDecimal, 2.00) - 1.00);
            secondChroma *= chroma; // commutative property

            float lightnessMatch = (convert.at(2) - (50.00 * chroma)) / 100.00;
            std::vector<float> formulatedValues {};
            switch (static_cast<int>(std::floor(hueDecimal))) {
                case 0:
                    formulatedValues = {chroma, secondChroma, 0};
                    break;
                case 1:
                    formulatedValues = {secondChroma, chroma, 0};
                    break;
                case 2:
                    formulatedValues = {0, chroma, secondChroma};
                    break;
                case 3:
                    formulatedValues = {0, secondChroma, chroma};
                    break;
                case 4:
                    formulatedValues = {secondChroma, 0, chroma};
                    break;
                case 5:
                    formulatedValues = {chroma, 0, secondChroma};
                    break;
            }

            convert.clear();
            for (float& f : formulatedValues) convert.push_back(std::lroundf((f + lightnessMatch) * 255));
            


            
        }
    }
}