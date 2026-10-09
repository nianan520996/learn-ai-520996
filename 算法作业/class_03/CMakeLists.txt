cmake_minimum_required(VERSION 3.16)
project(class_03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    src/MarkerManager.cpp
)

target_include_directories(main PRIVATE include)
