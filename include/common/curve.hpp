#pragma once

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>
#include <cmath>

namespace TOOLKIT {

    /******************************************************************************
     * UI class to display a colored curve with even width between points, based on
     * VertexArray with TriangleStrip.
     * Possibility to display a shade below the curve.
     ******************************************************************************/
    class Curve final : public sf::Transformable, public sf::Drawable {
        public:
        Curve(size_t nbSamples, sf::Color color, bool shaded);
        
        template<typename T>
        void update(const T& xValues, const T& yValues) {
            assert(xValues.size() <= nbSamples_);
            assert(xValues.size() == yValues.size());

            minY_ = std::min(minY_, yValues.back()), maxY_ = std::max(maxY_, yValues.back());
            vertices_.resize(2*xValues.size());
            for (std::size_t i=0; i<xValues.size()-1; i++) {
                vertices_[2*i].position = sf::Vector2f(xValues[i], yValues[i]);
                vertices_[2*i].color = color_;
                sf::Vector2f normal(yValues[i]-yValues[i+1], xValues[i+1]-xValues[i]);
                vertices_[2*i+1].position = normal.length() > 0 ? vertices_[2*i].position + WIDTH*normal/normal.length()
                        : vertices_[2*i].position;
                vertices_[2*i+1].color = color_;
                
                minY_ = std::min(minY_, yValues[i]); maxY_ = std::max(maxY_, yValues[i]);
            }
            vertices_[2*xValues.size()-2].position = sf::Vector2f(xValues.back(), yValues.back());
            vertices_[2*xValues.size()-2].color = color_;
            vertices_[2*xValues.size()-1].position = sf::Vector2f(xValues.back(), yValues.back()+WIDTH);
            vertices_[2*xValues.size()-1].color = color_;

            const auto f = [&](double y){
                return (uint8_t)(128.0*(maxY_-y)/(maxY_-minY_));
            };
            if (!shaded_) return;
            shade_.resize(2*xValues.size());
            for (size_t i=0; i<xValues.size(); i++) {
                shade_[2*i].position = sf::Vector2f(xValues[i], yValues[i]);
                shade_[2*i].color = {color_.r, color_.g, color_.b, f(yValues[i])};
                shade_[2*i+1].position = sf::Vector2f(xValues[i], maxY_);
                shade_[2*i+1].color = {color_.r, color_.g, color_.b, f(maxY_)};
            }
        }
        
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        private:
        size_t nbSamples_;
        sf::Color color_;
        bool shaded_;
        const float WIDTH = 5;
        sf::VertexArray vertices_;
        sf::VertexArray shade_;
        double minY_, maxY_;
    };

}