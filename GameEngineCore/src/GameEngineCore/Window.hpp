#pragma once

#include "GameEngineCore/Event.hpp"

#include <string>
#include <functional>

struct GLFWwindow;

namespace GameEngine
{
    class Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        Window(std::string title, const unsigned int width, const unsigned int height);
        ~Window();

        Window(const Window &) = delete;
        Window(Window &&) = delete;
        Window &operator=(const Window &) = delete;
        Window &operator=(Window &&) = delete;

        void on_update();
        unsigned int get_width() const { return m_data.width; }
        unsigned int get_height() const { return m_data.height; }

        void set_event_callback(const EventCallback& callback){
            m_data.event_callback = callback;
        }
    private:
    struct WindowData{
        std::string title;
        unsigned int width;
        unsigned int height;
        EventCallback event_callback;
    };

    GLFWwindow *m_window = nullptr;
    WindowData m_data;
    float m_background_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

    int init();
    void shutdown();
    };
}