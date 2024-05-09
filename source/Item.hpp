#include <set>
#include "Properties.hpp"
#include "Entity.hpp"
#include "SFMLTypedefs.hpp"
#pragma once

class Item : public Entity {
public:
	Item(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale) {

	}
	void changeDirection(bool& facesRight, bool changedDir) {
		this->facedRight = facesRight;
		this->facesRight = facesRight;
		if(changedDir) sprite.scale((this->facesRight != this->facedRight) ? 1 : -1, 1);
	}

	std::set<PROPERTIES> Properties;
	~Item() {}
	bool isEquipped = false;
	bool visible = true;
	float scale = 1;
protected:
	bool facesRight = false;
	bool facedRight = false;
	virtual void onUse(sf::Keyboard::Key key) = 0;
	virtual void onUse(sf::Mouse::Button button) = 0;
};