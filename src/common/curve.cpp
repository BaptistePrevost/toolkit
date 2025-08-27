#include "toolkit/common/curve.hpp"

using namespace TOOLKIT;

Curve::Curve(size_t nbSamples, sf::Color color, bool shaded) : nbSamples_(nbSamples), color_(color), shaded_(shaded),
    vertices_(sf::PrimitiveType::TriangleStrip), shade_(sf::PrimitiveType::TriangleStrip),
    minY_(MAXFLOAT), maxY_(-MAXFLOAT) {}

void Curve::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = nullptr;

    if (shaded_) target.draw(shade_, states);
    target.draw(vertices_, states);
}