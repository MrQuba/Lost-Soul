#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Colors.hpp"
#include "ExitCodes.hpp"
#pragma once

class Ground {
public:
    static void init(sf::RenderWindow& window);
    static void draw(sf::RenderWindow& window);
    static sf::RectangleShape& getPointerToShape();
    static EXIT_CODE collision_with_ground(sf::Sprite& sprt);
protected:
    static sf::RectangleShape shape;
};
