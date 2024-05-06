#include "Entity.hpp"
#pragma once

class Button : public Entity {
public:
	Button(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale){}
	bool isHoveredOn(sf::Sprite& sprite1, sf::RenderWindow& window) {
		if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) return true;
		else return false;
	}
	bool isPressed(sf::RenderWindow& window) {
		if (isHoveredOn(this->sprite, window)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHoveredOn(this->sprite, window)) {
				return true;
			}
			return false;

		}
		else {
			this->sprite.setTexture(texture);
			return false;
		}
	}
};
