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
include("${CMAKE_SOURCE_DIR}/lib/CMakeLists.txt")

# project/target codes here

project(colorsys)

find_package(ftxui REQUIRED)
find_package(fmt REQUIRED)

add_executable(colorsys "src/main.cpp")

target_link_libraries(colorsys
    colorsys_lib
    ftxui::screen
    ftxui::dom
    fmt::fmt
)