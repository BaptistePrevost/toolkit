#pragma once

#include "panels/panel.hpp"
#include "palette.hpp"

namespace TOOLKIT {
    
    /*****************************************************
     * Panel to display drawable items organized as a column.
     * The vertical space for each item is proportionnal to
     * the weight passed in addItem method.
     *****************************************************/
    class VerticalDisplayPanel final : public Panel {
        public:
        VerticalDisplayPanel(
            sf::Color fillColor = Colors::DEEP_BLUE,
            sf::Color outlineColor = Colors::WHITE
        );

        void initialize() override final;

        bool onMousePressed(const sf::Vector2f& coordinates) override final;
        
        void drag(const sf::Vector2f& vector) override final;
    };

}