#include <SFML/Graphics.hpp>
#pragma once

class HUD {
protected:
	sf::RectangleShape background;
	sf::RectangleShape hud;
public:
	HUD(sf::Color background, sf::Color hud, sf::Vector2f backgroundSize, sf::Vector2f hudSize, sf::Vector2f scale) {
		this->background.setFillColor(background);
		this->background.setSize(backgroundSize);
		this->background.setScale(scale);

		this->hud.setFillColor(hud);
		this->hud.setSize(hudSize);
		this->hud.setScale(-scale.x, scale.y);
	}
	void setHudPos(sf::Vector2f pos) {
		this->background.setPosition(pos);
		this->hud.setPosition(
			this->background.getPosition().x + this->background.getSize().x,
			this->background.getPosition().y
			);

	}
	void updateHUD(sf::View v, sf::Vector2f mult, float s) {
		// Change size of hud elements
		if (this->background.getSize().x < s) this->background.setSize(sf::Vector2f(s, this->background.getSize().y));
		else this->hud.setSize(sf::Vector2f(s, this->hud.getSize().y));
		// Sets hud elements on top left corner
		setHudPos(sf::Vector2f(
			v.getCenter().x + (v.getSize().x / 2) - (mult.x * this->background.getSize().x),
			v.getCenter().y - (v.getSize().y / 2) + (mult.y * this->background.getSize().y)
		));
	}
	void drawHud(sf::RenderWindow& window) const {
		window.draw(this->background);
		window.draw(this->hud);
	}
};