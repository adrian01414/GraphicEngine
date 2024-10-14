cmake_minimum_required (VERSION 3.8)

set(
    ENGINE_PROJECT_NAME 
    GameEngineCore
)
set(
    ENGINE_PUBLIC_INCLUDES
    include/GameEngineCore/Application.hpp
    include/GameEngineCore/Debug.hpp
)
set(
    ENGINE_PRIVATE_INCLUDES
    src/GameEngineCore/Window.hpp
)
set(
    ENGINE_PRIVATE_SOURCES
    src/GameEngineCore/Application.cpp
    src/GameEngineCore/Window.cpp
)

add_library(
    ${ENGINE_PROJECT_NAME} STATIC
    ${ENGINE_PUBLIC_INCLUDES}
    ${ENGINE_PRIVATE_INCLUDES}
    ${ENGINE_PRIVATE_SOURCES}
)

target_include_directories(
    ${ENGINE_PROJECT_NAME}
    PUBLIC include
    PRIVATE src
)

target_compile_features(
    ${ENGINE_PROJECT_NAME} PUBLIC
    cxx_std_20
)

target_link_libraries(
    ${ENGINE_PROJECT_NAME}
    glfw
    glad
    spdlog
)