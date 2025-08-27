#pragma once

#include <SFML/Graphics/Shape.hpp>

namespace TOOLKIT {

    /***************************************************
     * Custom shape of a rectangle with rounded corners.
     ***************************************************/
    class RoundedRectangle : public sf::Shape {
        public:
            RoundedRectangle(sf::Vector2f size = {0, 0}, float radius = 0);

            void setSize(sf::Vector2f size);
            sf::Vector2f getSize() const;
        
            void setRadius(float radius);
            float getRadius() const;
        
            std::size_t getPointCount() const override;
            sf::Vector2f getPoint(std::size_t index) const override;

        private:
            sf::Vector2f size_;
            float radius_;
	        static constexpr float PI = 3.141592654;
            static constexpr std::size_t corner_points = 16;
    };

}