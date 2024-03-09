#include <SFML/Graphics.hpp>
#include <iostream>
#include "ExitCodes.hpp"
#pragma once
class Entity {
	public:
		Entity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) {
			texture.loadFromFile(pathToTexture, txt);
			sprite.setTexture(texture);
			sprite.setScale(scale);
		}
		virtual void Update(sf::RenderWindow& window) = 0;
		EXIT_CODE draw(sf::RenderWindow& window) const {
			if (NULL == sprite.getTexture()) return EXIT_CODE::RETURNED_NULL;
			window.draw(sprite);
			return EXIT_CODE::OPERATION_SUCCESFUL;
		}
		sf::Sprite getSprite() {
			return sprite;
		}
		sf::Texture getTexture() {
			return texture;
		}
		~Entity() {
			texture.~Texture();
		}
	protected:
		sf::Sprite sprite;
		sf::Texture texture;
	};