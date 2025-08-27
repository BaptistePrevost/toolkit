#pragma once

#include "toolkit/panels/panel.hpp"

namespace TOOLKIT {

    /*****************************************************
     * Panel to display drawable items on top of eachother.
     *****************************************************/
    class StackedDisplayPanel final : public Panel {
        public:
        StackedDisplayPanel(
            sf::Color fillColor = CONF::BG_COLOR,
            sf::Color outlineColor = sf::Color(128, 128, 128)
        );

        void finalize() override final;

        void selectDrawable(const sf::Vector2f& coordinates);
        
        void drag(const sf::Vector2f& vector) override final;

    };

}