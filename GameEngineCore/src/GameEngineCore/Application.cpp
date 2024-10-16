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
        
        m_event_dispatcher.add_event_listener<EventMouseMoved>(
            [](EventMouseMoved &event) {
                //LOG_INFO("Mouse moved to x: {0}, y: {1}", event.x, event.y);
            }
        );

        m_event_dispatcher.add_event_listener<EventWindowResized>(
            [](EventWindowResized &event) {
                //LOG_INFO("Window resized to width: {0}, height: {1}", event.width, event.height);
            }
        );

        m_event_dispatcher.add_event_listener<EventWindowClose>(
            [&](EventWindowClose &event) {
                LOG_INFO("Window closed");
                m_bCloseWindow = true;
            }
        );

        m_window->set_event_callback(
            [&](Event& event){
                m_event_dispatcher.dispatch(event);
            }
        );

        while(!m_bCloseWindow){
            m_window->on_update();
            on_update();
        }
        m_window = nullptr;

        return 0;
    }
}
