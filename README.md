# Colorsys 
Color Theory in a shell!

> [!NOTE]
> This project is still in its early stages, so good code quality, optimization, and documentation is yet to be achieved

## Features ✨
- Convert between color systems (rgb, hsl, hex, and etc.)
- Generate color harmonies (complementary, analogous, and etc.)
- Adjust color mixtures (tint, shade, and etc.)

## Table of Contents 📖
- [General Usage](#general-usage)
- [Color Models](#available-color-modelspaces-)
- [Functions](#available-functions-)

## General Usage 🔎
```
colorsys <mode> "<color value>" [-m <magnitude, intensity>] [-r <range>] -i <input type> -o <output type>
```
### Available Color Model/Spaces 🎨
- cmy
- cmyk
- hsv
- hsl
- hwb
- rgb
- hex

### Available Functions 🔨
- [Analogous](docs/analogous.md)
- [Complementary](docs/complementary.md)
- [Split Complementary](docs/split_complementary.md)
- [Square](docs/square.md) 
- [Temperature](docs/temperature.md)
- Tint
- Triadic

## Conversion 🔁
```
# Convert hsv value of cyan to hex
colorsys convert "180, 100, 100" -i hsv -o hex

# Convert rgb value of orange to cmyk
colorsys convert "255, 165, 0" -i rgb -o cmyk
```


## Contributing
Want to fix something or add a new feature? Feel free to make a Pull Request or simply an Issue. But first, read the following files so you'll know what and how to add.
- CONTIBUTING.md
- BUILD.md

## License
This project, Colorsys, and its contributions are licensed under the GPL-3.0 license. See [license](LICENSE) for more details.

## Libraries used
- [ftxui](https://github.com/ArthurSonzogni/FTXUI)
- [fmt](https://github.com/fmtlib/fmt)


When I started creating this project, I didn't research a name for it; it simply popped up in my head, and when I found out that Python has a module with the same name and the same functionality, it was halfway done, so this name will probably stick here for a while. That's all, bye!