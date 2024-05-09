#include <SFML/Graphics.hpp>
#include "EquipableItem.hpp"
#include "Global.hpp"
#include "Collisions.hpp"
#pragma once

class Weapon : public EquipableItem {
public:	
	bool isAttacking = false;
	Weapon(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
	: EquipableItem(pathToTexture, txt, scale) {
		weapon = true;
	}
	void setOnMiddleOfPlayer() {
		this->sprite.setPosition(sf::Vector2f(
		GLOBAL::PLAYER_PTR->position().x + (GLOBAL::PLAYER_PTR->l_getBounds().width),
		GLOBAL::PLAYER_PTR->position().y + (GLOBAL::PLAYER_PTR->l_getBounds().height / 2)
		));
	}
	void setOnMiddleOfPlayer(sf::Vector2f offset) {
		this->sprite.setPosition(sf::Vector2f(
			(GLOBAL::PLAYER_PTR->position().x + GLOBAL::PLAYER_PTR->l_getBounds().width) + offset.x,
			(GLOBAL::PLAYER_PTR->position().y + GLOBAL::PLAYER_PTR->l_getBounds().height) + offset.y
		));
	}
};
