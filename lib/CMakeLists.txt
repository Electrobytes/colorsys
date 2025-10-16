cmake_minimum_required(VERSION 3.6)

project(colorsys_lib)

find_package(ftxui REQUIRED)


add_library(colorsys_lib STATIC
    "${CMAKE_CURRENT_LIST_DIR}/colorsys/engine.cpp"
)

target_include_directories(colorsys_lib PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/colorsys"
)

target_link_libraries(colorsys_lib PRIVATE
    ftxui::dom
    ftxui::screen    
)