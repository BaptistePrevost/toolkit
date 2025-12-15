#pragma once

#include <SFML/Graphics.hpp>

#include <toolkit/configuration.hpp>
#include <toolkit/common/drawable.hpp>
#include <toolkit/common/rounded_rectangle.hpp>

namespace TOOLKIT {

    /*******************************************************
     * Basic framed element that can be inserted in a window
     ******************************************************/
    class Panel : public Drawable {
        public:
        Panel(
            sf::Color fillColor = CONF::BG_COLOR,
            sf::Color outlineColor = sf::Color(128, 128, 128)
        );
        
        void draw(sf::RenderWindow &window) override final;
        
        void addItem(Drawable* drawable, float weight = 1.0);
        
        void setPadding(float padding);
        void setVerticalPadding(float padding);
        void setHorizontalPadding(float padding);

        void setFrameVisibility(bool showFrame);

        virtual void selectDrawable(const sf::Vector2f& coordinates) = 0;

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

    };

}