#include <SFML/Graphics.hpp>
#include "EquipableItem.hpp"
#include "Global.hpp"
#pragma once

class Weapon : public EquipableItem {
public:	
	Weapon(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
	: EquipableItem(pathToTexture, txt, scale) {

}
	void setOnMiddleOfPlayer() {
		this->sprite.setPosition(sf::Vector2f(
		GLOBAL::PLAYER_PTR->position().x + (GLOBAL::PLAYER_PTR->l_getBounds().width),
		GLOBAL::PLAYER_PTR->position().y + (GLOBAL::PLAYER_PTR->l_getBounds().height / 2)
		));
	}
};
