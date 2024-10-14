#include "GameEngineCore/Window.hpp"
#include "GameEngineCore/Debug.hpp"
#include "Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace GameEngine
{
    static bool s_GLfW_initialized = false;

    Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : m_title(std::move(title)), m_width(width), m_height(height)
    {
        int resultCode = init();
    }

    Window::~Window()
    {
        shutdown();
    }

    void Window::on_update()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    int Window::init()
    {
        if(!s_GLfW_initialized){
            if (!glfwInit()){
                LOG_CRITICAL("Failed to initialize GLFW");
                return -1;
            }
            s_GLfW_initialized= true;
        }
        
        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_window)
        {
            LOG_CRITICAL("Failed to create window");
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Failed to initialize GLAD");
            return -3;
        }

        return 0;
    }

    void Window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}