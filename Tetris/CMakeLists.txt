cmake_minimum_required(VERSION 3.20)

project (Tetris)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Tetris main.cc window.h window.cc renderer.h renderer.cc game_manager.h game_manager.cc)

target_link_libraries(Tetris ${SDL2_LIBRARIES})
