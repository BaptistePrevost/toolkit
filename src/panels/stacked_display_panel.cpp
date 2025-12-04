#include "panels/stacked_display_panel.hpp"

using namespace TOOLKIT;

StackedDisplayPanel::StackedDisplayPanel(sf::Color fillColor, sf::Color outlineColor)
         : Panel(fillColor, outlineColor) {}

void StackedDisplayPanel::initialize() {
    sf::Vector2f padding = {size_.x*horizontalPadding_, size_.y*verticalPadding_};
    for (const WeightedItem& item : items_) {
        item.drawable->setPosition(position_ + 0.5f*padding);
        item.drawable->setSize(size_ - padding);
        item.drawable->initialize();
    }
}

void StackedDisplayPanel::selectDrawable(const sf::Vector2f& coordinates) {
    selectedDrawable_ = this;
}

void StackedDisplayPanel::drag(const sf::Vector2f& vector) {
    for (const WeightedItem& item : items_) 
        item.drawable->drag(vector);
}