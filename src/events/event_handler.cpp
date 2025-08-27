#include "toolkit/events/event_handler.hpp"

using namespace TOOLKIT;
    
EventHandler::EventHandler() : key_press_handler_([](sf::Event::KeyPressed const& e) { return e.code; })
        , key_released_handler_([](sf::Event::KeyReleased const& e) { return e.code; })
        , mouse_pressed_handler_([](sf::Event::MouseButtonPressed const& e) { return e.button; })
        , mouse_released_handler_([](sf::Event::MouseButtonReleased const& e) { return e.button; }) {
    addCallback<sf::Event::KeyPressed>([this](sf::Event::KeyPressed const& e) {
        key_press_handler_.handle(e); });
    addCallback<sf::Event::KeyReleased>([this](sf::Event::KeyReleased const& e) {
        key_released_handler_.handle(e); });
    addCallback<sf::Event::MouseButtonPressed>([this](sf::Event::MouseButtonPressed const& e) {
        mouse_pressed_handler_.handle(e); });
    addCallback<sf::Event::MouseButtonReleased>([this](sf::Event::MouseButtonReleased const& e) {
        mouse_released_handler_.handle(e); });
}

void EventHandler::process(sf::Window& window) {
    while (const std::optional event = window.pollEvent()) {
        if (event.has_value()) {
            sf::Event const& valid_event{*event};
            for (auto const& callback : event_callbacks_) {
                callback->tryProcess(valid_event);
            }
        }
    }
}
    
void EventHandler::onKeyPressed(sf::Keyboard::Key const key_code, KeyPressedHandler::CallbackEvent callback) {
    key_press_handler_.setEventCallback(key_code, std::move(callback));
}

void EventHandler::onMousePressed(sf::Mouse::Button const button, MousePressedHandler::CallbackEvent callback) {
    mouse_pressed_handler_.setEventCallback(button, std::move(callback));
}

void EventHandler::onMouseReleased(sf::Mouse::Button const button, MouseReleasedHandler::CallbackEvent callback) {
    mouse_released_handler_.setEventCallback(button, std::move(callback));
}

void EventHandler::onMouseMoved(MouseMovedCallbackEvent callback) {
    addCallback<sf::Event::MouseMoved>(std::move(callback));
}

void EventHandler::onMouseWheelScrolled(MouseWheelScrolledCallbackEvent callback) {
    addCallback<sf::Event::MouseWheelScrolled>(std::move(callback));
}