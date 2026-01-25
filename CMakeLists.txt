cmake_minimum_required(VERSION 3.25)

project(Stranded)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Helps cross compilation/portability

add_executable(Stranded
    src/main.cpp
    src/Player.cpp
)

target_include_directories(Stranded PUBLIC
    include/
)
