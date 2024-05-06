#include <set>
#include "Properties.hpp"
#include "Entity.hpp"
#pragma once

class Item : public Entity {
public:
	Item(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale) {

	}
	std::set<PROPERTIES> Properties;
	~Item() {}
protected:
	virtual void onUse(sf::Keyboard::Key key) = 0;
	virtual void onUse(sf::Mouse::Button button) = 0;
};