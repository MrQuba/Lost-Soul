#include <SFML/Graphics.hpp>
#include <set>
#include "Event.hpp"
#include "Window.hpp"
#include "Constants.hpp"
#include "Entity.hpp"
#include "Items.hpp"
#pragma once

namespace GLOBAL {
	static Event EVENT;
	static Window game;
	static sf::Vector2f PLAYER_POSITION;
	static Entity* PLAYER_PTR;
	static std::set<Entity*>* ENTITIES_SET_POINTER;

	static std::map<ITEMS, Item*> ItemID;
}
