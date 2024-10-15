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
        : m_data({std::move(title), width, height})
    {
        int resultCode = init();
    }

    Window::~Window()
    {
        shutdown();
    }

    void Window::on_update()
    {
        glClearColor(1, 0, 0, 1);
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
        
        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
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

        glfwSetWindowUserPointer(m_window, &m_data);

        glfwSetWindowSizeCallback(m_window, 
            [](GLFWwindow* window, int width, int height){
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                data.height = height;
                data.width = width;

                EventWindowResized event(width, height);
                data.event_callback(event);
            }
        );

        glfwSetCursorPosCallback(m_window,
            [](GLFWwindow* window, double x, double y){
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

                EventMouseMoved event(x, y);
                data.event_callback(event);
            }
        );

        glfwSetWindowCloseCallback(m_window,
            [](GLFWwindow* window){
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                EventWindowClose event;
                data.event_callback(event);
            }
        );
        return 0;
    }

    void Window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}