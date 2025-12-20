#pragma once

#include "panels/panel.hpp"

namespace TOOLKIT {

    /*****************************************************
     * Panel to display drawable items on top of eachother.
     *****************************************************/
    class StackedDisplayPanel final : public Panel {
        public:
        StackedDisplayPanel(
            sf::Color fillColor = Colors::DEEP_BLUE,
            sf::Color outlineColor = Colors::BLACK
        );

        void initialize() override final;

        void selectDrawable(const sf::Vector2f& coordinates);
        
        void drag(const sf::Vector2f& vector) override final;

    };

}