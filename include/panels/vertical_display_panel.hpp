#pragma once

#include "panels/panel.hpp"

namespace TOOLKIT {
    
    /*****************************************************
     * Panel to display drawable items organized as a column.
     * The vertical space for each item is proportionnal to
     * the weight passed in addItem method.
     *****************************************************/
    class VerticalDisplayPanel final : public Panel {
        public:
        VerticalDisplayPanel(
            sf::Color fillColor = CONF::BG_COLOR,
            sf::Color outlineColor = sf::Color(128, 128, 128)
        );

        void initialize() override final;

        void selectDrawable(const sf::Vector2f& coordinates);
        
        void drag(const sf::Vector2f& vector) override final;
    };

}