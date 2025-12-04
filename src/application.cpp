#include "application.hpp"

using namespace TOOLKIT;

        
Application::Application(sf::Vector2u windowSize, std::string const& title, sf::State state) 
        : window_(sf::VideoMode(windowSize), title, state), size_(windowSize), paused_(false) {
    event_handler_ = std::make_unique<EventHandler>();

    //Register events
    event_handler_->onKeyPressed(sf::Keyboard::Key::Escape, [this](sf::Event::KeyPressed const&) {
            exit(); });
    event_handler_->onKeyPressed(sf::Keyboard::Key::Space, [this](sf::Event::KeyPressed const&) {
            togglePause(); });
}

void Application::run() {
    while (window_.isOpen()) {
        /* Events */
        event_handler_->process(window_);
            
        /* Logic */
        if (paused_) continue;
        tick();
        
        /* Render */
        window_.clear(CONF::BG_COLOR);
        draw();
        window_.display();
    }
}

void Application::exit() {
    window_.close();
}

void Application::togglePause() {
    paused_ = !paused_;
}

void Application::updateMousePosition() {
    mouse_position_ = sf::Mouse::getPosition(window_);
}