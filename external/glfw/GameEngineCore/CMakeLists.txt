cmake_minimum_required (VERSION 3.8)

set(ENGINE_PROJECT_NAME GameEngineCore)

add_library(
    ${ENGINE_PROJECT_NAME} STATIC
    src/GameEngineCore/Utils/test.cpp
    include/GameEngineCore/Utils/test.hpp
)

target_include_directories(
    ${ENGINE_PROJECT_NAME} PUBLIC
    include
)

target_compile_features(
    ${ENGINE_PROJECT_NAME} PUBLIC
    cxx_std_20
)