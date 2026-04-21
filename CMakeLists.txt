cmake_minimum_required(VERSION 3.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib")

include_directories("${CMAKE_SOURCE_DIR}/include")

project(colorsys_engine)
project(colorsys_convert)
project(colorsys_exec)

find_package(ftxui REQUIRED)
find_package(fmt REQUIRED)

set(COLORSYS_ENGINE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/engine")
set(COLORSYS_CONVERT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/ir")

add_library(colorsys_engine STATIC
    "${COLORSYS_ENGINE_DIR}/complementary.cpp"
    "${COLORSYS_ENGINE_DIR}/analogous.cpp"
    "${COLORSYS_ENGINE_DIR}/handler.cpp"
    "${COLORSYS_ENGINE_DIR}/shade.cpp"
    "${COLORSYS_ENGINE_DIR}/tint.cpp"
    "${COLORSYS_ENGINE_DIR}/split_complementary.cpp"
    "${COLORSYS_ENGINE_DIR}/square.cpp"
    "${COLORSYS_ENGINE_DIR}/triadic.cpp"
    "${COLORSYS_ENGINE_DIR}/temperature.cpp"
)

add_library(colorsys_convert STATIC
    "${COLORSYS_CONVERT_DIR}/rgb.cpp"
    "${COLORSYS_CONVERT_DIR}/cmy.cpp"
    "${COLORSYS_CONVERT_DIR}/cmyk.cpp"
    "${COLORSYS_CONVERT_DIR}/hsv.cpp"
    "${COLORSYS_CONVERT_DIR}/hwb.cpp"
    "${COLORSYS_CONVERT_DIR}/handler.cpp"
)

add_executable(colorsys_exec "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

target_link_libraries(colorsys_exec
    ftxui::screen
    ftxui::dom
    fmt::fmt
    colorsys_engine
    colorsys_convert
)