#include <SFML/Graphics.hpp>
#include "Event.hpp"
#pragma once
namespace CONSTANTS {
	// WINDOW DATA
	static const int FRAMERATE = 60;
	static const int WINDOW_SIZE_X = 1280;
	static const int WINDOW_SIZE_Y = 720;
	const sf::Vector2i WINDOW_SIZE(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	// CONTROLS
	const sf::Keyboard::Key UP = sf::Keyboard::W;
	const sf::Keyboard::Key DOWN = sf::Keyboard::S;
	const sf::Keyboard::Key LEFT = sf::Keyboard::A;
	const sf::Keyboard::Key RIGHT = sf::Keyboard::D;
	// ENVIROMENT
	const sf::Vector2f BASE_SPEED = sf::Vector2f(5.f, 5.f);
	const sf::Vector2f MAX_SPEED = sf::Vector2f(1.5f, 1.5f);
};