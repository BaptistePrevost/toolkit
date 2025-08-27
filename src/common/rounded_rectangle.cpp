#include "toolkit/common/rounded_rectangle.hpp"
#include <math.h>

using namespace TOOLKIT;


RoundedRectangle::RoundedRectangle(sf::Vector2f size, float radius) : size_(size), radius_(radius) {
    update();
};

void RoundedRectangle::setSize(sf::Vector2f size) { size_ = size; update(); };

sf::Vector2f RoundedRectangle::getSize() const { return size_; }

void RoundedRectangle::setRadius(float radius) { radius_ = radius; update(); }

float RoundedRectangle::getRadius() const { return radius_; }

std::size_t RoundedRectangle::getPointCount() const { return 4 * corner_points; }

sf::Vector2f RoundedRectangle::getPoint(std::size_t index) const {
    float da = 90.f / (corner_points - 1);
    auto centre_i = index / corner_points;

    sf::Vector2f centre{centre_i == 1 || centre_i == 2 ? radius_ : size_.x - radius_,
                        centre_i == 0 || centre_i == 1 ? radius_ : size_.y - radius_};

    return {radius_ * std::cos(da * (index - centre_i) * PI / 180) + centre.x,
        -radius_ * std::sin(da * (index - centre_i) * PI / 180) + centre.y};
}