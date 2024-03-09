#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "ExitCodes.hpp"
#include "Views.hpp"
#include "Minimap.hpp"
#include "Constants.hpp"
#include "Global.hpp"
#pragma once
using namespace CONSTANTS;
struct STATS
{
	int HEALTH = BASE_HEALTH;
	sf::Vector2f CURRENT_SPEED = BASE_SPEED;
}PLAYER;
class Player : public Entity {
public:
	Player(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) 
		: Entity(pathToTexture, txt, scale){

	}
	void Update(sf::RenderWindow& window) {
		handleInput();
		//TODO, fix zoom
		minimap.moveView(this->VELOCITY);
		camera.moveViewAndSprite(this->VELOCITY, sprite);
	}


	~Player() {
	}
private:
	View camera;
	Minimap minimap;
	float currentZoom = 1.f;
	sf::Vector2f VELOCITY = sf::Vector2f(0,0);
	void handleInput() {
		// reset of velocity
		this->VELOCITY.x = 0;
		this->VELOCITY.y = 0;
		// reassigning speed if key is pressed
		// this solution seems much cleaner than another while(window.pollEvent(event)) loop
		// that detects if key was pressed/released
		if(sf::Keyboard::isKeyPressed(UP))this->VELOCITY.y += -PLAYER.CURRENT_SPEED.y;
		if (sf::Keyboard::isKeyPressed(DOWN))this->VELOCITY.y += PLAYER.CURRENT_SPEED.y;
		if (sf::Keyboard::isKeyPressed(LEFT))this->VELOCITY.x += -PLAYER.CURRENT_SPEED.x;
		if (sf::Keyboard::isKeyPressed(RIGHT))this->VELOCITY.x += PLAYER.CURRENT_SPEED.x;
		if (sf::Keyboard::isKeyPressed(ZOOM_IN))camera.Zoom(0.9f);
		if (sf::Keyboard::isKeyPressed(ZOOM_OUT))camera.Zoom(1.1f);
	}
};
