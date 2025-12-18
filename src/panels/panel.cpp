#include "panels/panel.hpp"
#include <cassert>

using namespace TOOLKIT;

Panel::Panel(sf::Color fillColor, sf::Color outlineColor) {
    frame_.setFillColor(fillColor);
    frame_.setOutlineThickness(3);
    frame_.setOutlineColor(outlineColor);

    totalWeight_ = 0;
    verticalPadding_ = 0;
    horizontalPadding_ = 0;

    selectedDrawable_ = nullptr;
}

void Panel::draw(sf::RenderWindow &window) {
    if (showFrame_) drawFrame(window, position_, size_);
    for (const WeightedItem& item : items_)
        item.drawable->draw(window);
}

void Panel::addItem(Drawable* drawable, float weight) {
    items_.emplace_back(drawable, weight);
    totalWeight_ += weight;
}

void Panel::setPadding(float padding) {
    assert(padding>=0 && padding<=1.0);
    setVerticalPadding(padding);
    setHorizontalPadding(padding);
}

void Panel::setVerticalPadding(float padding) {
    assert(padding>=0 && padding<=1.0);
    verticalPadding_= padding;
}

void Panel::setHorizontalPadding(float padding) {
    assert(padding>=0 && padding<=1.0);
    horizontalPadding_= padding;
}

void Panel::setFrameVisibility(bool showFrame) {
    showFrame_ = showFrame;
}

void Panel::selectDrawableIfMissing(const sf::Vector2f& coordinates) {
    if (selectedDrawable_ == nullptr) selectDrawable(coordinates);
}

void Panel::drawFrame(sf::RenderWindow &window,
        const sf::Vector2f &containerPosition,
        const sf::Vector2f &containerDimensions)  {
    frame_.setPosition(containerPosition);
    frame_.setSize(containerDimensions);
    window.draw(frame_);


}