#pragma once

#include <SFML/Graphics.hpp>
#include "events/event_callback.hpp"
#include "events/event_category_handler.hpp"

namespace TOOLKIT {
    
    class EventHandler {
        public:
        using KeyPressedHandler = EventCategoryHandler<sf::Keyboard::Key, sf::Event::KeyPressed>;
        using KeyReleasedHandler = EventCategoryHandler<sf::Keyboard::Key, sf::Event::KeyReleased>;
        using MousePressedHandler = EventCategoryHandler<sf::Mouse::Button, sf::Event::MouseButtonPressed>;
        using MouseReleasedHandler = EventCategoryHandler<sf::Mouse::Button, sf::Event::MouseButtonReleased>;

        using MouseMovedCallbackEvent = std::function<void(sf::Event::MouseMoved const&)>;
        using MouseWheelScrolledCallbackEvent = std::function<void(sf::Event::MouseWheelScrolled const&)>;

        virtual ~EventHandler() = default;
        
        EventHandler();

        void process(sf::Window& window);

        template <typename TEvent>
        void addCallback(std::function<void(TEvent const&)> callback) {
            event_callbacks_.push_back(
                std::unique_ptr<EventCallbackBase>(
                    new EventCallback<TEvent>(std::move(callback))
                )
            );
        }
        
        void onKeyPressed(sf::Keyboard::Key const key_code, KeyPressedHandler::CallbackEvent callback);
        void onMousePressed(sf::Mouse::Button const button, MousePressedHandler::CallbackEvent callback);
        void onMouseReleased(sf::Mouse::Button const button, MouseReleasedHandler::CallbackEvent callback);
        void onMouseMoved(MouseMovedCallbackEvent callback);
        void onMouseWheelScrolled(MouseWheelScrolledCallbackEvent callback);

        private:
        KeyPressedHandler key_press_handler_;
        KeyReleasedHandler key_released_handler_;
        MousePressedHandler mouse_pressed_handler_;
        MouseReleasedHandler mouse_released_handler_;
        std::vector<std::unique_ptr<EventCallbackBase>> event_callbacks_;      

    };
}