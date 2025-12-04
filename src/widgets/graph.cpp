#include "widgets/graph.hpp"

using namespace TOOLKIT;

Graph::Graph() {}

void Graph::add(Accessor accessor, sf::Color color) {
    accessors_.push_back(accessor);
    colors_.push_back(color);
    series_.push_back({});
    curves_.push_back(Curve(MAX_NB_SAMPLES_, color, true));
    lowestValue_ = 1e10;
    highestValue_ = -1e10;
    nbSamples_ = 0;
}

void Graph::draw(sf::RenderWindow &window) {
    incrementSeries();
    if (nbSamples_ < 2) return;
    double a = size_.y / (lowestValue_ - highestValue_);
    double b = position_.y + size_.y - a * lowestValue_;
    std::vector<double> xValues(nbSamples_);
    for(size_t j=0; j<nbSamples_; j++) xValues[j] = position_.x + j * size_.x / (MAX_NB_SAMPLES_ - 2);
    for(size_t i=0; i<series_.size(); i++) {
        std::vector<double> yValues(nbSamples_);
        for(size_t j=0; j<nbSamples_; j++) yValues[j] = a*series_[i][j] + b;
        curves_[i].update(xValues, yValues);
        window.draw(curves_[i]);
    }
}

void Graph::initialize() {}

void Graph::drag(const sf::Vector2f&) {}

void Graph::incrementSeries() {
    for(size_t i=0; i<accessors_.size(); i++) {
        series_[i].push_back(accessors_[i]());
        lowestValue_ = std::min(lowestValue_, static_cast<double>(series_[i].back()));
        highestValue_ = std::max(highestValue_, static_cast<double>(series_[i].back()));
        if(series_[i].size() > MAX_NB_SAMPLES_) series_[i].pop_front();
    }
    nbSamples_ = std::min(nbSamples_+1, MAX_NB_SAMPLES_);
}