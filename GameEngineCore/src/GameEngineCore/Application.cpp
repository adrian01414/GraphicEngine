#include "GameEngineCore/Application.hpp"
#include "GameEngineCore/Debug.hpp"
#include "GameEngineCore/Window.hpp"

#include <memory>

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
        m_window = std::make_unique<Window>(title, window_width, window_height);

        while(true){
            m_window->on_update();
            on_update();
        }

        return 0;
    }
}
