#pragma once

#include <toolkit/common/drawable.hpp>

namespace TOOLKIT {

    /************************************************************
     * Very simple class to display a double metric with a title.
     ************************************************************/
    class Metric : public Drawable {
        public:
        Metric(std::string title, double *metric);

        void draw(sf::RenderWindow &window);

        void initialize() override final;

        void drag(const sf::Vector2f& vector) override final;
        
        private:
        std::string title_;
        double *metric_;
        sf::Font font_;
    };
    
}