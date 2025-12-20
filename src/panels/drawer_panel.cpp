#include "panels/drawer_panel.hpp"
#include <cassert>

using namespace TOOLKIT;

DrawerPanel::DrawerPanel(sf::Vector2f size, sf::Vector2f openPosition, sf::Vector2f closedPosition, sf::Color fillColor, sf::Color outlineColor)
        : openPosition_(openPosition), closedPosition_(closedPosition), open_(false), Panel(fillColor, outlineColor) {
    setPosition(closedPosition);
    setSize(size);
    getFrame().setRadius(20);
}

void DrawerPanel::initialize() {}

bool DrawerPanel::selectDrawable(const sf::Vector2f& coordinates) {
    if (coordinates.x < position_.x || coordinates.y < position_.y) return false;
    if (coordinates.x > position_.x + size_.x || coordinates.y > position_.y + size_.y) return false;
    if (open_) {
        open_ = false;
        setPosition(closedPosition_);
    } else {
        open_ = true;
        setPosition(openPosition_);
    }
    return true;
}

void DrawerPanel::drag(const sf::Vector2f& vector) {}