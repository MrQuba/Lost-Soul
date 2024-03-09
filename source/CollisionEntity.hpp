#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class CollisionEntity : public Entity {
public:
	CollisionEntity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale) {

	}
	void Update(sf::RenderWindow& window) {
		printf("collision entity");
	}
};
