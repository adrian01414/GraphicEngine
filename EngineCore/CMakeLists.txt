cmake_minimum_required (VERSION 3.8)

set(
    ENGINE_PROJECT_NAME 
    EngineCore
)
set(
    ENGINE_PUBLIC_INCLUDES
    include/EngineCore/Application.hpp
    include/EngineCore/Debug.hpp
    include/EngineCore/Event.hpp
)
set(
    ENGINE_PRIVATE_INCLUDES
    src/EngineCore/Window.hpp
    src/EngineCore/Rendering/OpenGL/ShaderProgram.hpp
    src/EngineCore/Rendering/OpenGL/VertexBuffer.hpp
    src/EngineCore/Rendering/OpenGL/VertexArray.hpp
    src/EngineCore/Rendering/OpenGL/IndexBuffer.hpp
)
set(
    ENGINE_PRIVATE_SOURCES
    src/EngineCore/Application.cpp
    src/EngineCore/Window.cpp
    src/EngineCore/Rendering/OpenGL/ShaderProgram.cpp
    src/EngineCore/Rendering/OpenGL/VertexBuffer.cpp
    src/EngineCore/Rendering/OpenGL/VertexArray.cpp
    src/EngineCore/Rendering/OpenGL/IndexBuffer.cpp
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
    imgui
    glm
)

set(
    IMGUI_INCLUDES
    ../external/imgui/imgui.h
    ../external/imgui/backends/imgui_impl_glfw.h
    ../external/imgui/backends/imgui_impl_opengl3.h
)

set(
    IMGUI_SOURCES
    ../external/imgui/imgui.cpp
    ../external/imgui/backends/imgui_impl_glfw.cpp
    ../external/imgui/backends/imgui_impl_opengl3.cpp
    ../external/imgui/imgui_demo.cpp
    ../external/imgui/imgui_draw.cpp
    ../external/imgui/imgui_tables.cpp
    ../external/imgui/imgui_widgets.cpp
)

add_library(
    imgui STATIC
    ${IMGUI_INCLUDES}
    ${IMGUI_SOURCES}
)

target_include_directories( imgui PUBLIC includes ../external )
target_include_directories( imgui PUBLIC includes ../external/imgui )

target_link_libraries(
    imgui
    glad
    glfw
)