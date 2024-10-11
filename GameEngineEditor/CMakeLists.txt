cmake_minimum_required (VERSION 3.8)

set(EDITOR_PROJECT_NAME GameEngineEditor)

add_executable(
    ${EDITOR_PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(
    ${EDITOR_PROJECT_NAME}
    GameEngineCore
)

target_compile_features(
    ${EDITOR_PROJECT_NAME} PUBLIC
    cxx_std_20
)

set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)