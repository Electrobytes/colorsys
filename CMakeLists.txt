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

project(engine)
project(ir)
project(colorsys)

find_package(ftxui REQUIRED)
find_package(fmt REQUIRED)

add_library(engine STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/complementary.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/analogous.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/handler.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/shade.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/tint.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/split_complementary.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/square.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/triadic.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/temperature.cpp"
)

add_library(ir STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ir/rgb.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ir/cmy.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ir/cmyk.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ir/hsv.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ir/handler.cpp"
)

add_executable(colorsys "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

target_link_libraries(colorsys
    ftxui::screen
    ftxui::dom
    fmt::fmt
    engine
    ir
)