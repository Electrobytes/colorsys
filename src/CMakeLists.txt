cmake_minimum_required(VERSION 3.6)

project(engine)

find_package(ftxui REQUIRED)
find_package(fmt REQUIRED)

add_library(engine STATIC
    "${CMAKE_CURRENT_LIST_DIR}/engine.cpp"
)

# target_include_directories(engine PUBLIC 
#     "${CMAKE_CURRENT_SOURCE_DIR}/include"
# )

project(colorsys)

add_executable(colorsys "${CMAKE_CURRENT_LIST_DIR}/main.cpp")

target_link_libraries(colorsys
    ftxui::screen
    ftxui::dom
    fmt::fmt
    engine
)