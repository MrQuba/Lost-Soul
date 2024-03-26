#include "Constants.hpp"
#pragma once

class PlayerStats {
public:
	 PlayerStats() {
		HEALTH = CONSTANTS::BASE_HEALTH;
		INSANITY = 0;
		CURRENT_SPEED = CONSTANTS::BASE_SPEED;
		JUMP_VELOCITY = 9.f;
	}
	 int HEALTH;
	 int INSANITY;
	 sf::Vector2f CURRENT_SPEED;
	 float JUMP_VELOCITY;
};