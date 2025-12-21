#pragma once

#include <SFML/Graphics.hpp>

#include "palette.hpp"
#include "common/drawable.hpp"
#include "common/rounded_rectangle.hpp"

namespace TOOLKIT {

    /*******************************************************
     * Basic framed element that can be inserted in a window
     ******************************************************/
    class Panel : public Drawable {
        public:
        Panel(
            sf::Color fillColor = Colors::DEEP_BLUE,
            sf::Color outlineColor = Colors::WHITE
        );
        
        void draw(sf::RenderWindow &window) override final;

        bool isIn(const sf::Vector2f &coordinates) override final;
        
        void addItem(Drawable* drawable, float weight = 1.0);
        
        void setPadding(float padding);
        void setVerticalPadding(float padding);
        void setHorizontalPadding(float padding);

        void setFrameVisibility(bool showFrame);

        void selectDrawableIfMissing(const sf::Vector2f& coordinates);

        protected:
        struct WeightedItem {
            Drawable* drawable;
            float weight;

            WeightedItem(Drawable* d, float w)
                : drawable(d), weight(w) {}
        };
        bool showFrame_;
        RoundedRectangle frame_;
        std::vector<WeightedItem> items_;
        float totalWeight_;
        float verticalPadding_;
        float horizontalPadding_;
        Drawable* selectedDrawable_;

        void drawFrame(sf::RenderWindow &window,
                const sf::Vector2f &containerPosition,
                const sf::Vector2f &containerDimensions);

        RoundedRectangle& getFrame();

    };

}