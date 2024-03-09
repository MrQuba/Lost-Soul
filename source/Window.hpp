#include <SFML/Graphics.hpp>
#include <cmath>
#pragma once
	class Window {
	public:
		sf::RenderWindow window;
		Window( int Width,  int Heigth, const char* Title, int Framerate) {
			window.create(sf::VideoMode(Width, Heigth), Title);
			window.setFramerateLimit(Framerate);
		}
		Window(sf::Vector2i Size, const char* Title, int Framerate) {
			window.create(sf::VideoMode(abs(Size.x), abs(Size.y)), Title);
			window.setFramerateLimit(Framerate);
		}
	};