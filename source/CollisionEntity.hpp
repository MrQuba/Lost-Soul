#include "Entity.hpp"
#include "Collisions.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class CollisionEntity : public Entity {
public:
	CollisionEntity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale) {
	}
	
	void Update(sf::RenderWindow& window){}

	void Update(sf::RenderWindow& window, sf::Sprite& s) {
		Collisions::spritesIntersectWithCollision(this->sprite, s);
	}
};
