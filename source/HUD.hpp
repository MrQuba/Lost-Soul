#include <SFML/Graphics.hpp>
#pragma once

class HUD {
protected:
	sf::RectangleShape background;
	sf::RectangleShape hud;
public:
	HUD(sf::Color background, sf::Color hud, sf::Vector2f backgroundSize, sf::Vector2f hudSize, sf::Vector2f scale, bool ps = false) {
		this->background.setFillColor(background);
		this->background.setSize(backgroundSize);
		this->background.setScale(scale);

		this->hud.setFillColor(hud);
		this->hud.setSize(hudSize);
		this->hud.setScale((ps) ? -1 : 1 * scale.x, scale.y);
	}
	void setHudPos(sf::Vector2f pos) {
		this->background.setPosition(pos.x * this->background.getScale().x, pos.y * this->background.getScale().y);
		this->hud.setPosition(
			(this->background.getPosition().x + this->background.getSize().x) * this->background.getScale().x,
			this->background.getPosition().y * this->background.getScale().y
			);

	}
	void setHudPos(sf::Vector2f pos , bool isPlayer) {
		this->background.setPosition(pos.x * this->background.getScale().x, pos.y * this->background.getScale().y);
		this->hud.setPosition(
			this->background.getPosition().x * this->background.getScale().x,
			this->background.getPosition().y * this->background.getScale().y
		);

	}
	sf::Vector2f getSizeOfHUD() {
		return this->background.getSize();
	}
	void updateHUD( float s) {
		// Change size of hud elements
		this->hud.setSize(sf::Vector2f(s, this->hud.getSize().y));
		if (this->background.getSize().x < s) this->background.setSize(sf::Vector2f(s, this->background.getSize().y));
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
	void scaleHud(float sx, float sy) {
		this->background.setScale(sx, sy);
		this->hud.setScale(sx, sy);
	}
	void drawHud(sf::RenderWindow& window) const {
		window.draw(this->background);
		window.draw(this->hud);
	}
};