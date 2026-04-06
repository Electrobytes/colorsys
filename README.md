# Colorsys
Color Theory in the cmd!

## Features
- Convert between color systems (rgb, hsl, hex, and etc.)
- Generate color harmonies (complementary, analogous, and etc.)
- Adjust color mixtures (tint, shade, and etc.)

## Table of Contents
- [General Usage](#general-usage)
-

## General Usage
```
colorsys <mode> "<color code>" [-m <magnitude, intensity>] [-r <range>] -i <input type> -o <output type>
```
## Conversion
```
# Convert hsv value of cyan to hex
colorsys convert "180, 100, 100" -i hsv -o hex

# Convert rgb value of orange to cmyk
colorsys convert "255, 165, 0" -i rgb -o cmyk
```

## Libraries used
- [ftxui](https://github.com/ArthurSonzogni/FTXUI)
- [fmt](https://github.com/fmtlib/fmt)


When I started creating this project, I didn't research a name for it; it simply popped up in my head, and when I found out that Python has a module with the same name and the same functionality, it was halfway done, so this name will probably stick here for a while.