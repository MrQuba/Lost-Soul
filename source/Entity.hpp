#include <SFML/Graphics.hpp>
#include <iostream>
#include "ExitCodes.hpp"
#pragma once
class Entity {
	public:
		Entity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) {
			gravity = true;
			texture.loadFromFile(pathToTexture, txt);
			sprite.setTexture(texture);
			sprite.setScale(scale);
		}
		virtual void Update(sf::RenderWindow& window) = 0;
		virtual int onHit() = 0;
		EXIT_CODE draw(sf::RenderWindow& window) const {
			if (NULL == sprite.getTexture()) return EXIT_CODE::RETURNED_NULL;
			window.draw(sprite);
			return EXIT_CODE::OPERATION_SUCCESFUL;
		}
		sf::Sprite* getSprite() {
			return &this->sprite;
		}
		sf::Texture* getTexture() {
			return &this->texture;
		}
		void damage(int dmg) {

		}
		bool affectedByGravity() const {
			return gravity;
		}
		~Entity() {
		}
		EXIT_CODE setPosition(sf::Vector2f p) {
			this->sprite.setPosition(p.x, p.y);
			return EXIT_CODE::OPERATION_SUCCESFUL;
		}
		sf::Vector2f position() {
			return this->sprite.getPosition();
		}
		sf::FloatRect l_getBounds() {
			return this->sprite.getLocalBounds();
		}
		sf::FloatRect g_getBounds() {
			return this->sprite.getGlobalBounds();
		}
	protected:
		bool gravity;
		sf::Sprite sprite;
		sf::Texture texture;
	};