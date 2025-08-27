#include "toolkit/panels/vertical_display_panel.hpp"

using namespace TOOLKIT;

VerticalDisplayPanel::VerticalDisplayPanel(sf::Color fillColor, sf::Color outlineColor)
        : Panel(fillColor, outlineColor) {}

void VerticalDisplayPanel::finalize() {
    sf::Vector2f cumulatedPosition = position_;
    for (const WeightedItem& item : items_) {
        sf::Vector2f dimensions = {size_.x, item.weight * size_.y / totalWeight_};
        item.drawable->setPosition(cumulatedPosition);
        item.drawable->setSize(dimensions);
        item.drawable->finalize();
        cumulatedPosition += {0, dimensions.y};
    }
}

void VerticalDisplayPanel::selectDrawable(const sf::Vector2f& coordinates) {
    for (const WeightedItem& item : items_) {
        assert(item.drawable != nullptr);
        if (item.drawable->getPosition().y<=coordinates.y
                && coordinates.y<=item.drawable->getPosition().y+item.drawable->getSize().y) {
            selectedDrawable_ = item.drawable;
            break;
        }
    }
}

void VerticalDisplayPanel::drag(const sf::Vector2f& vector) {
    // Find the top layer element and apply to it
    selectedDrawable_->drag(vector);
}