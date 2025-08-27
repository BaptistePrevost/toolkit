#ifndef TOOLKIT_DRAWABLE_H
#define TOOLKIT_DRAWABLE_H

#include <SFML/Graphics.hpp>

namespace TOOLKIT {

    /*******************************************************
     * Basic drawable element that can be inserted in a panel
     ******************************************************/
    class Drawable {
        public:
        virtual ~Drawable() = default;
        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void finalize() = 0;
        virtual void drag(const sf::Vector2f& vector) = 0;

        const sf::Vector2f& getPosition() const { return position_; }
        void setPosition(const sf::Vector2f& position) { position_ = position; }
        const sf::Vector2f& getSize() const { return size_; }
        void setSize(const sf::Vector2f& size) { size_ = size; }

        protected:
        sf::Vector2f position_;
        sf::Vector2f size_;
    };
}

#endif // UI_DRAWABLE_H