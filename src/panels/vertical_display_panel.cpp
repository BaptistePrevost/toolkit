#include "panels/vertical_display_panel.hpp"
#include <cassert>

using namespace TOOLKIT;

VerticalDisplayPanel::VerticalDisplayPanel(sf::Color fillColor, sf::Color outlineColor)
        : Panel(fillColor, outlineColor) {}

void VerticalDisplayPanel::initialize() {
    sf::Vector2f cumulatedPosition = position_;
    for (const WeightedItem& item : items_) {
        sf::Vector2f dimensions = {size_.x, item.weight * size_.y / totalWeight_};
        item.drawable->setPosition(cumulatedPosition);
        item.drawable->setSize(dimensions);
        item.drawable->initialize();
        cumulatedPosition += {0, dimensions.y};
    }
}

bool VerticalDisplayPanel::onMousePressed(const sf::Vector2f &coordinates) {
    for (WeightedItem& item : items_) {
        if (!item.drawable->onMousePressed(coordinates)) continue;
        selectedDrawable_ = item.drawable;
        return true;
    }
    return isIn(coordinates);
}

void VerticalDisplayPanel::drag(const sf::Vector2f& vector) {
    // Find the top layer element and apply to it
    selectedDrawable_->drag(vector);
}