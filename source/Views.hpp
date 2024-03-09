#include <SFML/Graphics.hpp>
#include "ExitCodes.hpp"
#include "Constants.hpp"
#pragma once

class View {
private:
	sf::View view;
public:
	sf::View getView() {
		return this->view;
	}
	View(sf::Vector2f center, sf::Vector2f size) {
		view.setCenter(center);
		view.setSize(size);
	}
	View() {
		sf::Vector2f size = sf::Vector2f(CONSTANTS::WINDOW_SIZE);
		view.setCenter(size.x / 2, size.y / 2);
		view.setSize(size);
	}
	EXIT_CODE moveView(sf::Vector2f m) {
		view.move(m);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE moveViewAndSprite(sf::Vector2f m, sf::Sprite& sprt) {
		view.move(m);
		setSpriteInMiddleOfView(sprt);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE setSpriteInMiddleOfView(sf::Sprite& sprt) {
		sprt.setPosition(view.getCenter());
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
};