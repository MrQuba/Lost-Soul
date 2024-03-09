#include <SFML/Graphics.hpp>
#include "ExitCodes.hpp"
#include "Constants.hpp"
#include "Global.hpp"
#pragma once

class View {
protected:
	sf::View view;
public:
	sf::View getView() {
		return this->view;
	}
	View(sf::Vector2f center, sf::Vector2f size) {
		view.setCenter(center);
		view.setSize(size);
	}
	/// <summary>
	/// Default Constructor, that uses CONSTANTS::WINDOW_SIZE for declaration
	/// </summary>
	View() {
		sf::Vector2f size = sf::Vector2f(CONSTANTS::WINDOW_SIZE);
		view.setCenter(size.x / 2, size.y / 2);
		view.setSize(size);
	}
	EXIT_CODE updateView() {
		GLOBAL::game.window.setView(this->view);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE moveView(sf::Vector2f vel) {
		this->view.move(vel);
		updateView();
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE Zoom(float z) {
		this->view.zoom(z);
		updateView();
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE resetZoom() {
		this->view.zoom(1);
		updateView();
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	/// <summary>
	/// Function that calls moveView and setSpriteInMiddleOfView functions
	/// </summary>
	/// <param name="vel">sf::Vector2f - velocity of view, distance it will be moved</param>
	/// <param name="sprt">sf::Sprite - sprite that will be placed in middle of view</param>
	/// <returns></returns>
	EXIT_CODE moveViewAndSprite(sf::Vector2f vel, sf::Sprite& sprt) {
		moveView(vel);
		updateView();
		setSpriteInMiddleOfView(sprt);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	EXIT_CODE setSpriteInMiddleOfView(sf::Sprite& sprt) {
		sprt.setPosition(this->view.getCenter());
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
};