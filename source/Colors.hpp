#include <SFML/Graphics.hpp>
#pragma once
enum class COLOUR {
	BASE_SKY,
	BASE_GRASS,
	HUD_BACKGROUND,
	BASE_HEALTH,
	BASE_INSANITY

};
class Colour{
public:
	static sf::Color getColour(COLOUR c){
		switch (c) {
		case COLOUR::BASE_SKY: return sf::Color(69, 108, 133, 255);
		case COLOUR::BASE_GRASS: return sf::Color(61, 49, 47, 255);
		case COLOUR::HUD_BACKGROUND: return sf::Color(56, 47, 46, 255);
		case COLOUR::BASE_HEALTH: return sf::Color(133, 64, 53, 255);
		case COLOUR::BASE_INSANITY: return sf::Color(73, 92, 80, 255);
		default: return sf::Color(0, 0, 0, 255);
		}
	}
};