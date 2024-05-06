#include "Entity.hpp"
#include "Global.hpp"
#include "Collisions.hpp"
#include "Colors.hpp"
#include "Effects.hpp"
#pragma once

class TownGuard : public Entity {
public:	
	TownGuard(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale, int hp)
	: Entity(pathToTexture, txt, scale),
		healthBar(Colour::getColour(COLOUR::HUD_BACKGROUND), Colour::getColour(COLOUR::BASE_HEALTH),
			sf::Vector2f(hp, HUD_HEIGHT), sf::Vector2f(hp, HUD_HEIGHT), sf::Vector2f(1.f, 1.f)) {
	this->mortal = true;
	this->health = hp;
	std::cout << this->health << std::endl;
}
	virtual void Update(sf::RenderWindow& window) override {
		gravityForce();
		directionOld = direction;
		if (!isOnPlayer()) {
			if (isPlayerOnLeft())
				direction = -1;
			else direction = 1;
			if (direction != directionOld) this->sprite.scale(-1, 1);
			this->sprite.move((direction * CONSTANTS::BASE_SPEED.x) / 2, 0);
		}
		for (Entity* ent : *GLOBAL::ENTITIES_SET_POINTER)
			Collisions::isHit(this, ent);
		updateHUDElements();
	}
	virtual int onHit(Entity* Target) override {
		// TODO, fix knockback logic
		// this->sprite.move(-1 * ((direction * CONSTANTS::BASE_SPEED.x) - 0.5f), 0.3f);
		if (!Target->isMortal()) return 0;
		Target->damage(this->dealdamage);
		Target->addEffect(&Effects::insanity);
		return 0;
	}
	EXIT_CODE drawHUDElements(sf::RenderWindow& window) const {
		healthBar.drawHud(window);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	virtual EXIT_CODE draw(sf::RenderWindow& window) override {
		Entity::draw(window);
		drawHUDElements(GLOBAL::game.window);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE updateHUDElements() {
		healthBar.updateHUD(sf::Vector2f(1, 1), this->health);
		healthBar.scaleHud(direction, 1);
		healthBar.setHudPos(
			sf::Vector2f(
				this->sprite.getPosition().x,
				this->sprite.getPosition().y - healthBar.getSizeOfHUD().y
			));
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	bool isPlayerOnLeft() {
		if (GLOBAL::PLAYER_PTR->position().x < this->sprite.getPosition().x) return true;
		else return false;
	}
	bool isOnPlayer() {
		if (GLOBAL::PLAYER_PTR->position().x == this->sprite.getPosition().x) return true;
		else return false;
	}
protected:
	HUD healthBar;
	short directionOld = 1;
	int dealdamage = 5;
	short direction = 1;
};
