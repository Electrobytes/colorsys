cmake_minimum_required(VERSION 3.6)

project(colorsys_engine)

find_package(ftxui REQUIRED)


add_library(colorsys_engine STATIC
    "${CMAKE_CURRENT_LIST_DIR}/colorsys/engine.cpp"
)

target_include_directories(colorsys_engine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/colorsys"
)

target_link_libraries(colorsys_engine PRIVATE
    ftxui::dom
    ftxui::screen    
)