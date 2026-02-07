cmake_minimum_required(VERSION 3.20)

project(WordHunt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Helps cross compilation/portability

add_executable(WordHunt
    src/main.cpp
    src/Player.cpp
    src/GameFlow.cpp
    src/GameState.cpp
    
)

target_include_directories(WordHunt PUBLIC
    include/
)
