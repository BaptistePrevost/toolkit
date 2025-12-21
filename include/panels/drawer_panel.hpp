#pragma once

#include "panels/panel.hpp"

namespace TOOLKIT {

    /*******************************************************
     * Drawer element that can be open or closed on 
     * the side of the screen.
     * 
     ******************************************************/
    class DrawerPanel final : public Panel {
        public:
        DrawerPanel(
            sf::Vector2f size,
            sf::Vector2f openPosition,
            sf::Vector2f closedPosition,
            sf::Color fillColor = Colors::NAVY,
            sf::Color outlineColor = Colors::WHITE
        );

        void initialize() override final;

        bool onMousePressed(const sf::Vector2f& coordinates) override final;
        
        void drag(const sf::Vector2f& vector) override final;

        private:
        const sf::Vector2f openPosition_;
        const sf::Vector2f closedPosition_;
        bool open_;
    };

}