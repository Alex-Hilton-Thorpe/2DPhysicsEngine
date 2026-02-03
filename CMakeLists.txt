cmake_minimum_required(VERSION 3.20)

project(2DPhysicsEngine
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(physics_sim
    src/main.cpp
)

target_include_directories(physics_sim
    PRIVATE include
)
