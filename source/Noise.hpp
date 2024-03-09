#include <SFML/Graphics.hpp>
#pragma once

class Noise {
public:
	/// <summary>
	/// Area of Noise
	/// </summary>
	static sf::Vector2i area;
	/// <summary>
	/// Sets area for noise generator
	/// </summary>
	/// <param name="v"> takes sf::Vector2i as argument</param>
	/// <returns>sf::Vector2i</returns>
	static sf::Vector2i setAreaSize(sf::Vector2i v) {
		area = v;
		return area;
	}
	/// <summary>
	/// Sets area for noise generator
	/// </summary>
	/// <param name="w">takes unsigned int width argument</param>
	/// <param name="h">takes unsigned int height argument</param>
	/// <returns>sf::Vector2i</returns>
	static sf::Vector2i setAreaSize(unsigned int w, unsigned int h) {
		area = sf::Vector2i(w,h);
		return area;
	}

};