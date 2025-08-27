#include "toolkit/widgets/metric.hpp"

using namespace TOOLKIT;

Metric::Metric(std::string title, double *metric) : title_(title), metric_(metric) {
    if (!font_.openFromFile("Akira Expanded Demo.otf")) {
        throw std::runtime_error("Failed to load font!");
    }
}

void Metric::draw(
    sf::RenderWindow &window) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << *metric_;
    
    sf::Text text = sf::Text(font_);
    text.setString(ss.str());
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    window.draw(text);
}

void Metric::finalize() {}

void Metric::drag(const sf::Vector2f&) {}