#include "GameEngineCore/Application.hpp"

namespace GameEngine
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    int Application::start(unsigned int window_width, unsigned int window_height, const char *title)
    {
        GLFWwindow *window;

        if (!glfwInit())
            return -1;

        window = glfwCreateWindow(window_width, window_height, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        if(!gladLoadGL()){
            return -1;
        }

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();

            on_update();
        }

        glfwTerminate();
        return 0;
    }
}
