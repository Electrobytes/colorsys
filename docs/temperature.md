# Temperature (Colder/Warmer)
Shifts the input color towards the colder (blues or greens) or warmer (reds or oranges) part of the color wheel. Replicating the direct variation of temperature units, Positive values "warm" the color, whereas negative values "cool" it. The temperature can be spacified through the magnitude flag (-m). There is also the "warmer" function which is simple an alias to the temperature function, and the "colder" function "cools" the input color for a positive magnitude.
## Usage
```
colorsys (temperature / colder / warmer) "<color value>" -m <temp intensity> -i <input color model> -o <output color model>

```