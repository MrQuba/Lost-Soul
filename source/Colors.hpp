#include <SFML/Graphics.hpp>
#pragma once
enum class COLOUR {
	BASE_SKY,
	BASE_GRASS
};
class Colour{
public:
	static sf::Color getColour(COLOUR c){
		switch (c) {
		case COLOUR::BASE_SKY: return sf::Color(69, 108, 133, 255);
		case COLOUR::BASE_GRASS: return sf::Color(47, 74, 47, 255);
		default: return sf::Color(0, 0, 0, 255);
		}
	}
};