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
	const sf::Keyboard::Key ZOOM_IN = sf::Keyboard::Num9;
	const sf::Keyboard::Key ZOOM_OUT = sf::Keyboard::Num0;
	const sf::Keyboard::Key JUMP = sf::Keyboard::Space;
	const sf::Keyboard::Key HEALTH_UP = sf::Keyboard::Num1;
	const sf::Keyboard::Key HEALTH_DOWN = sf::Keyboard::Num2;
	const sf::Keyboard::Key INSANITY_UP = sf::Keyboard::Num3;
	const sf::Keyboard::Key INSANITY_DOWN = sf::Keyboard::Num4;
	// ENVIROMENT
	const static float GRAVITY = 0.098f;
	const static int SECTOR_I_WIDTH = 12800;
	const static int SECOTR_I_HEIGHT = 720;
	// PLAYER_STATS
	const static int BASE_HEALTH = 100;
	const static float HUD_HEIGHT = 16;
	const static int MAX_INSANITY = 200;
	const sf::Vector2f BASE_SPEED = sf::Vector2f(5.f, 5.f);
	const sf::Vector2f MAX_SPEED = sf::Vector2f(1.5f, 1.5f);
};