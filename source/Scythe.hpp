#include <SFML/Graphics.hpp>
#include "Weapon.hpp"
#pragma once

class Scythe : public Weapon {
public:	
	Scythe(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
	: Weapon(pathToTexture, txt, scale) {
		this->sprite.setOrigin(sf::Vector2f(
		this->sprite.getLocalBounds().width / 2,
		this->sprite.getLocalBounds().height / 2
		));
	}
	virtual void onUse(sf::Mouse::Button button) override {
		if (sf::Mouse::isButtonPressed(button)) {
			this->sprite.rotate(5.f);
			if (this->sprite.getRotation() > 135) this->sprite.setRotation(0);
		}
		else this->sprite.setRotation(0);
	}
	virtual int onHit() override {
		return 9;
	}

	virtual void Update(sf::RenderWindow& window) override {
		setOnMiddleOfPlayer();
		onUse(sf::Mouse::Left);

	}
	virtual ITEMS equip() override {
		return ITEMS::SCYTHE;
	}
	virtual void onUse(sf::Keyboard::Key key) override {}
};


