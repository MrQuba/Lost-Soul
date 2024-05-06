#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ExitCodes.hpp"
#include "Constants.hpp"
#include "Ground.hpp"
#include "Effect.hpp"
#include "Triple.hpp"
#include "Item.hpp"
class Entity {
public:
	unsigned int health;
	unsigned int insanity;
	Entity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) {
		gravity = true;
		texture.loadFromFile(pathToTexture, txt);
		sprite.setTexture(texture);
		sprite.setScale(scale);
	}
	virtual void Update(sf::RenderWindow& window) = 0;
	virtual int onHit(Entity* Target) = 0;
	virtual EXIT_CODE draw(sf::RenderWindow& window) {
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
	virtual void damage(int dmg) {
		this->health -= dmg;
	}
	bool isMortal() const {
		return this->mortal;
	}
	int getHealth() const {
		return this->health;
	}
	bool affectedByGravity() const {
		return this->gravity;
	}
	bool isDead() const {
		return this->health > 0;
	}
	void manageEffects(Triple<int, int, bool> triple, Effect* effect) {
		if (triple.getFirst() == 1) this->insanity += triple.getSecond();
		else if (triple.getFirst() == 10) this->health += triple.getSecond();

		if (!triple.getThird()) removeEffect(effect);
	}
	void removeEffect(Effect* effectToRemove) {
		auto iter = std::remove_if(this->currentEffects.begin(), this->currentEffects.end(),
			[effectToRemove](Effect* effect) {
				return effect == effectToRemove;
			});
		if (iter != this->currentEffects.end()) {
			std::cout << "Effect found and removed." << std::endl;
			this->currentEffects.erase(iter, this->currentEffects.end());
		}
		else {
			std::cout << "Effect not found." << std::endl;
		}
	}
	EXIT_CODE gravityForce() {
		if (!this->affectedByGravity()) return EXIT_CODE::NOT_AFFECTED_BY_GRAVITY;
		this->sprite.move(0, 2.5 * CONSTANTS::GRAVITY);
		while (Ground::collision_with_ground(this->sprite) == EXIT_CODE::SPRITE_COLLIDED) {
			this->sprite.move(0, -0.1f);
		}
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
	void addEffect(Effect* ef) {
		currentEffects.push_back(ef);
	}
	/// <summary>
	/// Checks if Entity has effects
	/// </summary>
	/// <returns>
	/// True if currentEffects is not empty,
	/// False otherwise
	/// </returns>
	bool hasEffects() {
		return currentEffects.empty();
	}
	/// <summary></summary>
	/// <returns>a pointer to vector containing effects of entity</returns>
	std::vector<Effect*>* getEffectVectorPointer() {
		return &this->currentEffects;
	}
	/// <summary> </summary>
	/// <returns>vector containing effects of entity </returns>
	std::vector<Effect*> getEffectVector() {
		return this->currentEffects;
	}
	bool isPlayer() const{
		return this->player;
	}
	protected:
		std::vector<Effect*> currentEffects;
		bool player = false;
		bool mortal;
		bool gravity;
		sf::Sprite sprite;
		sf::Texture texture;
	};
#endif