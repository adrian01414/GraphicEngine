#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace GameEngine {
    class Application
    {
    public:
        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        virtual int start(unsigned int window_width, unsigned int window_height, const char* title);

        virtual void on_update(){}
    private:
    };
}