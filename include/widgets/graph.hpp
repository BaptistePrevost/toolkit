#pragma once

#include <cmath>
#include <deque>
#include <functional>

#include "common/drawable.hpp"
#include "common/curve.hpp"

namespace TOOLKIT {

    class Graph : public Drawable {
        public:
        typedef std::function<double()> Accessor;

        Graph();

        void add(Accessor accessor, sf::Color color);

        void draw(sf::RenderWindow &window) override final;

        void initialize() override final;

        void drag(const sf::Vector2f&) override final;

        private:
        std::vector<Accessor> accessors_;
        std::vector<sf::Color> colors_;
        std::vector<std::deque<double>> series_;
        std::vector<TOOLKIT::Curve> curves_;
        const size_t MAX_NB_SAMPLES_ = 200;
        size_t nbSamples_;

        double lowestValue_, highestValue_;
        double lineWidth_ = 0.0f;

        void incrementSeries();
    };

}