#include "Ground.hpp"

sf::RectangleShape Ground::shape;
void Ground::init(sf::RenderWindow& window) {
    shape.setSize(sf::Vector2f(CONSTANTS::SECTOR_I_WIDTH, CONSTANTS::SECOTR_I_HEIGHT));
    shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
    shape.setFillColor(Colour::getColour(COLOUR::BASE_GRASS));
    shape.setPosition(0, window.getSize().y + (2 / CONSTANTS::SECOTR_I_HEIGHT));
}

void Ground::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Ground::getPointerToShape() {
    return shape;
}
EXIT_CODE Ground::collision_with_ground(sf::Sprite& sprt) {
    sf::FloatRect spriteBounds = sprt.getGlobalBounds();
    sf::FloatRect groundBounds = Ground::getPointerToShape().getGlobalBounds();

    if (spriteBounds.intersects(groundBounds)) {
        return EXIT_CODE::SPRITE_COLLIDED;
    }
    return EXIT_CODE::RETURN_VOID;
}