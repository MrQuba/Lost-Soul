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
		mortal = false;
		knockback = true;
		health = hp;
		std::cout << this->health << std::endl;
		damage = 2;
	}
	virtual void Update(sf::RenderWindow& window) override {
		Entity::Update(window);
		gravityForce();
		directionOld = direction;
		if (!isOnPlayer()) {
			isPlayerOnLeft() ? direction = -1 : direction = 1;
			this->sprite.scale((direction != directionOld) ? -1 : 1, 1);
			this->sprite.move((direction * CONSTANTS::BASE_SPEED.x) / 2, 0);
		}
		for (Entity* ent : *GLOBAL::ENTITIES_SET_POINTER)
			Collisions::isHit(this, ent);
		updateHUDElements();
	}
	virtual int onHit(Entity* Target) override {
		return (Entity::onHit(Target) == 0) ? 0 : [](Entity* t, int d, int dir) -> int {
			t->dealDamage(d);
			t->dealKnockback(dir);
			return d;
			}(Target, damage, direction);
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
		healthBar.updateHUD((float)this->health);
		healthBar.setHudPos(
			sf::Vector2f(
				this->sprite.getPosition().x - ((healthBar.getSizeOfHUD().x / 2)),
				this->sprite.getPosition().y - healthBar.getSizeOfHUD().y
			), false);
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
};
