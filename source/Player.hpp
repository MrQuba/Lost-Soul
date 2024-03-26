#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "ExitCodes.hpp"
#include "Views.hpp"
#include "Minimap.hpp"
#include "Constants.hpp"
#include "Global.hpp"
#include "HUD.hpp"
#include "Colors.hpp"
#include "Items.hpp"
#include "Pointers.hpp"
#include "PlayerStats.hpp"
#pragma once
using namespace CONSTANTS;
struct INVENTORY {
	ITEMS WEAPON = ITEMS::SCYTHE;
}INVENTORY;
class Player : public Entity {
public:
	Player(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) 
		: Entity(pathToTexture, txt, scale), 
		health(Colour::getColour(COLOUR::HUD_BACKGROUND), Colour::getColour(COLOUR::BASE_HEALTH), 
			sf::Vector2f(STAT.HEALTH, HUD_HEIGHT), sf::Vector2f(STAT.HEALTH, HUD_HEIGHT), sf::Vector2f(1.f, 1.f)),
		insanity(Colour::getColour(COLOUR::HUD_BACKGROUND), Colour::getColour(COLOUR::BASE_INSANITY),
			sf::Vector2f(MAX_INSANITY, HUD_HEIGHT), sf::Vector2f(STAT.INSANITY, HUD_HEIGHT), sf::Vector2f(1.f, 1.f)) {
		// init pointers
		float psx = STAT.CURRENT_SPEED.x;
		POINTER::PLAYER_SPEED_X = &psx;
		// init pos of health bar
		health.setHudPos(sf::Vector2f(
		WINDOW_SIZE_X - STAT.HEALTH,
		WINDOW_SIZE_Y + HUD_HEIGHT
		));
		// init pos of insanity bar
		insanity.setHudPos(sf::Vector2f(
			WINDOW_SIZE_X - MAX_INSANITY,
			WINDOW_SIZE_Y + HUD_HEIGHT
		));
	}
	void Update(sf::RenderWindow& window) {
		handleInput();
		if(affectedByGravity() && !isJumping) this->VELOCITY.y += 2.5 * GRAVITY;
		//minimap.moveView(this->VELOCITY);
		camera.moveViewAndSprite(this->VELOCITY, sprite, this->canJump, this->isJumping);
		updateHUDElements();
	}
	virtual int onHit() override {

		return 2;
	}
	EXIT_CODE drawHUDElements(sf::RenderWindow& window) {
		health.drawHud(window);
		insanity.drawHud(window);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}

	EXIT_CODE updateHUDElements() {
		health.updateHUD(camera.getView(), sf::Vector2f(1.f,1.f), STAT.HEALTH);
		insanity.updateHUD(camera.getView(), sf::Vector2f(1.f, 2.2f), STAT.INSANITY);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	~Player() {
	}
	EXIT_CODE setPosOfSpriteAndView() {
		setPosition(sf::Vector2f(this->position().x, GLOBAL::PLAYER_POSITION.y));
		camera.setViewInMiddleOfSprite(this->sprite);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
private:
	PlayerStats STAT;
	bool gravity = true;
	bool canJump = true;
	bool isJumping = false;
	View camera;
	Minimap minimap;
	HUD health;
	HUD insanity;
	float currentZoom = 1.f;
	sf::Vector2f VELOCITY = sf::Vector2f(0,0);
	void handleInput() {
		if (this->VELOCITY.x == 0) GLOBAL::PLAYER_POSITION = position();
		// 1. reset of velocity
		this->VELOCITY.x = 0;
		if (!isJumping)
			this->VELOCITY.y = 0;
		else this->VELOCITY.y += GRAVITY;
		// 2. reassigning speed if key is pressed
	//	if(sf::Keyboard::isKeyPressed(UP))this->VELOCITY.y += -CURRENT_SPEED.y;
		if (sf::Keyboard::isKeyPressed(DOWN))this->VELOCITY.y += STAT.CURRENT_SPEED.y;
		if (sf::Keyboard::isKeyPressed(LEFT))this->VELOCITY.x += -STAT.CURRENT_SPEED.x;
		if (sf::Keyboard::isKeyPressed(RIGHT))this->VELOCITY.x += STAT.CURRENT_SPEED.x;
		if (sf::Keyboard::isKeyPressed(JUMP) && canJump) {
			this->canJump = false;
			this->isJumping = true;
			this->VELOCITY.y = -STAT.JUMP_VELOCITY;
		}
		// 3. this solution seems much cleaner than another while(window.pollEvent(event)) loop
		// 4. that detects if key was pressed/released
			
		if (sf::Keyboard::isKeyPressed(ZOOM_IN))camera.Zoom(0.9f);
		if (sf::Keyboard::isKeyPressed(ZOOM_OUT))camera.Zoom(1.1f);
		/* STAT CHANGE TESTS
		if (sf::Keyboard::isKeyPressed(HEALTH_DOWN)) HEALTH--;
		if (sf::Keyboard::isKeyPressed(HEALTH_UP)) HEALTH++;
		if (sf::Keyboard::isKeyPressed(INSANITY_UP)) INSANITY++;
		if (sf::Keyboard::isKeyPressed(INSANITY_DOWN)) INSANITY--; */
	}
};
