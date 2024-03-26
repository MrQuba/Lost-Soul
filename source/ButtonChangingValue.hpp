#include <SFML/Graphics.hpp>
#include "Button.hpp"
#pragma once
template <typename T>
class ButtonChangingValue : public Button {
public:
	T** pointerToAValue;
	T changeOfAValue;
	ButtonChangingValue(T** p, T change, std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Button(pathToTexture, txt, scale) {
		this->pointerToAValue = p;
		this->changeOfAValue = change;
	}
	virtual void Update(sf::RenderWindow& window) override {
		while (isPressed(window)) {
			**this->pointerToAValue += this->changeOfAValue;
			printf("now: %f \n", **this->pointerToAValue);
			break;
		}
	}
	virtual int onHit() override { return 0; }
};
