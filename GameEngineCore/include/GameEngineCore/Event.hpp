#pragma once

#include <functional>
#include <array>

namespace GameEngine
{
    enum class EventType
    {
        WindowResize = 0,
        WindowClose,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,

        EventsCount
    };

    struct Event
    {
        virtual ~Event() = default;
        virtual EventType get_type() const = 0;
    };

    class EventDispatcher
    {
    public:
        template <typename EventType>
        void add_event_listener(std::function<void(EventType &)> callback)
        {
            auto baseCallback = [func = std::move(callback)](Event &event)
            {
                if (event.get_type() == EventType::type)
                {
                    func(static_cast<EventType &>(event));
                }
            };
            m_eventsCallbacks[static_cast<size_t>(EventType::type)] = std::move(baseCallback);
        }

        void dispatch(Event &event){
            auto& callback = m_eventsCallbacks[static_cast<size_t>(event.get_type())];
            if(callback)
                callback(event);
        }
    private:
        std::array<std::function<void(Event &)>, static_cast<size_t>(EventType::EventsCount)> m_eventsCallbacks;
    };

    struct EventMouseMoved : public Event
    {
        EventMouseMoved(const double x, const double y) : x(x), y(y) {}

        virtual EventType get_type() const override { return type; }

        double x;
        double y;

        static const EventType type = EventType::MouseMoved;
    };

    struct EventWindowResized : public Event
    {
        EventWindowResized(const unsigned int width, const unsigned int height) : width(width), height(height) {}

        virtual EventType get_type() const override { return type; }

        unsigned int width;
        unsigned int height;

        static const EventType type = EventType::WindowResize;
    };

    struct EventWindowClose : Event {
        virtual EventType get_type() const override { return type; }

        static const EventType type = EventType::WindowClose;
    };
}