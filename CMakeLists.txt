cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME GraphicsEngine)
project(${PROJECT_NAME})

add_subdirectory(EngineCore)
add_subdirectory(EngineEditor)
add_subdirectory(external)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EngineEditor)