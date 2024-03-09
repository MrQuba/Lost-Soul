#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "ExitCodes.hpp"
#include "Views.hpp"
#include "Constants.hpp"
#include "Global.hpp"
#pragma once
using namespace CONSTANTS;
class Player : public Entity {
public:
	Player(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) 
		: Entity(pathToTexture, txt, scale){

	}
	void Update(sf::RenderWindow& window) {
		handleInput();
		camera.moveViewAndSprite(this->VELOCITY, sprite);
	}


	~Player() {
	}
private:
	View camera;
	sf::Vector2f VELOCITY;
	void handleInput() {
		// reset of velocity
		this->VELOCITY.x = 0;
		this->VELOCITY.y = 0;
		// reassigning speed if key is pressed
		// this solution seems much cleaner than another while(window.pollEvent(event)) loop
		if(sf::Keyboard::isKeyPressed(UP))this->VELOCITY.y += -BASE_SPEED.y;
		if (sf::Keyboard::isKeyPressed(DOWN))this->VELOCITY.y += BASE_SPEED.y;
		if (sf::Keyboard::isKeyPressed(LEFT))this->VELOCITY.x += -BASE_SPEED.x;
		if (sf::Keyboard::isKeyPressed(RIGHT))this->VELOCITY.x += BASE_SPEED.x;
	}
};
