#include "Views.hpp"
#include "Global.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class Minimap : public View {
public:
	Minimap() : View() {
		view.setSize(128, 72);
		view.setCenter(CONSTANTS::WINDOW_SIZE.x - view.getSize().x / 2, view.getSize().y / 2);
		view.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
	}
	void drawMinimap() {
		// TODO, add drawing of minimap
	}

};