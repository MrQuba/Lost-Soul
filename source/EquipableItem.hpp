#include "Item.hpp"
#include "Items.hpp"
#pragma once

class EquipableItem : public Item {
public:	
	EquipableItem(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
	: Item(pathToTexture, txt, scale) {}
	virtual ITEMS equip();
};
