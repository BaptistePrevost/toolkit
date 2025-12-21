#pragma once

#include "panels/panel.hpp"

namespace TOOLKIT {

    /*****************************************************
     * Panel to display drawable items on top of eachother.
     *****************************************************/
    class StackedDisplayPanel final : public Panel {
        public:
        StackedDisplayPanel(
            sf::Color fillColor = Colors::NAVY,
            sf::Color outlineColor = Colors::OVERLAY
        );

        void initialize() override final;

        bool onMousePressed(const sf::Vector2f& coordinates) override final;
        
        void drag(const sf::Vector2f& vector) override final;

    };

}