#include <SFML/Graphics.hpp>
#include "Weapon.hpp"
#include "Constants.hpp"
#pragma once

class Scythe : public Weapon {
public:	
	Scythe(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
	: Weapon(pathToTexture, txt, scale) {
		this->sprite.setOrigin(sf::Vector2f(
		this->sprite.getLocalBounds().width / 2,
		this->sprite.getLocalBounds().height
		));
		this->mortal = false;
		damage = 50;
	}
	virtual void onUse(sf::Mouse::Button button) override {
		if (sf::Mouse::isButtonPressed(button)) {
			isAttacking = true;
			this->sprite.rotate(((facesRight) ? 1 : -1) * 2.5f);
			if (this->sprite.getRotation() > 135 && facesRight)
				this->sprite.setRotation(0);
			else if (this->sprite.getRotation() < 225 && !facesRight)
				this->sprite.setRotation(0);
		}
		else {
			this->sprite.setRotation(0);
			isAttacking = false;
		}
	}
	virtual int onHit(Entity* Target) override {
		return (Entity::onHit(Target) == 0) ? 0 : [](Entity* t, int d) -> int {
			t->dealKnockback(t->getDirection());
			t->dealDamage(d);
			return d;
			}(Target, damage);
	}

	virtual void Update(sf::RenderWindow& window) override {
		Entity::Update(window);
		if (isEquipped) {
			setOnMiddleOfPlayer(sfc::Vector2f(
				[dir = facesRight]() -> float {
				return (dir) ? -(2 * CONSTANTS::PLAYER_SIZE.x) : (0.5f * CONSTANTS::PLAYER_SIZE.x);
				}, 
				CONSTANTS::PLAYER_SIZE.y).return_sfVector2());
			onUse(sf::Mouse::Left);
		}
		if (isAttacking) {
			for (Entity* ent : *GLOBAL::ENTITIES_SET_POINTER)
				Collisions::isHit(this, ent);
		}

	}
	virtual ITEMS equip() override {
		isEquipped = true;
		return ITEMS::SCYTHE;
	}
	virtual void onUse(sf::Keyboard::Key key) override {}
protected:
};


