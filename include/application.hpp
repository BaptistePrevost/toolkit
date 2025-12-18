#pragma once

#include <SFML/Graphics.hpp>
#include "events/event_handler.hpp"
#include "panels/panel.hpp"
#include <memory>


namespace TOOLKIT {
    
    class Application {
        public:
        virtual ~Application() = default;
        
        Application(sf::Vector2u windowSize, std::string const& title, sf::State state);

        void run();

        void exit();

        void togglePause();

        
        protected:
        sf::RenderWindow window_;
        sf::Clock clock_;
        
        const sf::Vector2f origin_ = {0, 0};
        const sf::Vector2f size_;

        bool paused_;
        sf::Vector2i mouse_position_;

        std::unique_ptr<EventHandler> event_handler_;
        
        virtual void tick() = 0;
        virtual void draw() = 0;
        virtual void initialize() = 0;

        void updateMousePosition();
    };

}