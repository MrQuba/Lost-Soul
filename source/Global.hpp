#include <SFML/Graphics.hpp>
#include <set>
#include "Event.hpp"
#include "Window.hpp"
#include "Constants.hpp"
#include "Entity.hpp"
#pragma once

namespace GLOBAL {
	static Event EVENT;
	static Window game;
	static Window debug;
	static Window op;
	static sf::Vector2f PLAYER_POSITION;
	static Entity* PLAYER_PTR;
	static std::set<Entity*>* ENTITIES_SET_POINTER;
}
