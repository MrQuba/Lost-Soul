#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "ExitCodes.hpp"
#include "Views.hpp"
#include "Constants.hpp"
#include "Global.hpp"
#include "HUD.hpp"
#include "Colors.hpp"
#include "Pointers.hpp"
#include "Inventory.hpp"

#pragma once
using namespace CONSTANTS;
class PlayerStats;
class Player : public Entity {
public:
	Player(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale) 
		: Entity(pathToTexture, txt, scale), 
		healthBar(Colour::getColour(COLOUR::HUD_BACKGROUND), Colour::getColour(COLOUR::BASE_HEALTH), 
			sf::Vector2f(BASE_HEALTH, HUD_HEIGHT), sf::Vector2f(BASE_HEALTH, HUD_HEIGHT), sf::Vector2f(1.f, 1.f), true),
		insanityBar(Colour::getColour(COLOUR::HUD_BACKGROUND), Colour::getColour(COLOUR::BASE_INSANITY),
			sf::Vector2f(MAX_INSANITY, HUD_HEIGHT), sf::Vector2f((float)this->insanity, HUD_HEIGHT), sf::Vector2f(1.f, 1.f), true) {
		// init stats
		std::cout << healthBar.getSizeOfHUD().x << std::endl;
		this->health = BASE_HEALTH;
		this->insanity = 0;
		this->CURRENT_SPEED = BASE_SPEED;
		this->JUMP_VELOCITY = 9.f;
		// init tags
		this->player = true;
		this->mortal = false;
		// init pointers
		float psx = this->CURRENT_SPEED.x;
		POINTER::PLAYER_SPEED_X = &psx;
		// init pos of health bar
		healthBar.setHudPos(sf::Vector2f(
		WINDOW_SIZE_X - (float)this->health,
		WINDOW_SIZE_Y + HUD_HEIGHT
		));
		// init pos of insanity bar
		insanityBar.setHudPos(sf::Vector2f(
			WINDOW_SIZE_X - MAX_INSANITY,
			WINDOW_SIZE_Y + HUD_HEIGHT
		));
		inventory.equipItem(ITEMS::SCYTHE, SLOTS::HAND); //temp
	}
	void Update(sf::RenderWindow& window) {
		Entity::Update(window);
		handleInput();
		if(affectedByGravity() && !isJumping) this->VELOCITY.y += 2.5f * GRAVITY;
		camera.moveViewAndSprite(this->VELOCITY, sprite, this->canJump, this->isJumping);
		for (Effect* effect : currentEffects) {
			manageEffects(effect->update(), effect);
		}
		this->inventory.updateEquipped(window, facesRight, facesRight != facedRight);
		if (0 > this->insanity) this->insanity = 0;
		if (0 > this->health) this->health = 0;
		updateHUDElements();
	}
	virtual EXIT_CODE draw(sf::RenderWindow& window) override{
		Entity::draw(window);
		drawHUDElements(GLOBAL::game.window);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	virtual int onHit(Entity* Target) override {
		return (Entity::onHit(Target) == 0) ? 0 : [](Entity* t, int d) -> int {
			t->dealDamage(d);
			return d;
			}(Target, damage);
	}
	EXIT_CODE drawHUDElements(sf::RenderWindow& window) {
		healthBar.drawHud(window);
		insanityBar.drawHud(window);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}

	EXIT_CODE updateHUDElements() {
		healthBar.updateHUD(camera.getView(), sf::Vector2f(1.f,1.f), (float)this->health);
		insanityBar.updateHUD(camera.getView(), sf::Vector2f(1.f, 2.2f), (float)this->insanity);
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
	Inventory inventory;
	float JUMP_VELOCITY;
	bool gravity = true;
	bool canJump = true;
	bool isJumping = false;
	bool facesRight = false;
	bool facedRight = false;
	sf::Vector2f CURRENT_SPEED;
	View camera;
	HUD healthBar;
	HUD insanityBar;
	float currentZoom = 1.f;
	sf::Vector2f VELOCITY = sf::Vector2f(0,0);


	void handleInput() {
		this->facedRight = facesRight;
		if (this->VELOCITY.x == 0) GLOBAL::PLAYER_POSITION = position();
		// 1. reset of velocity
		this->VELOCITY.x = 0;
		if (!isJumping)
			this->VELOCITY.y = 0;
		else this->VELOCITY.y += GRAVITY;
		// 2. reassigning speed if key is pressed
		if (sf::Keyboard::isKeyPressed(DOWN))this->VELOCITY.y += this->CURRENT_SPEED.y;
		if (sf::Keyboard::isKeyPressed(LEFT)) {
			this->VELOCITY.x += -this->CURRENT_SPEED.x;
			facesRight = false;
		}
		if (sf::Keyboard::isKeyPressed(RIGHT)) {
			this->VELOCITY.x += this->CURRENT_SPEED.x;
			facesRight = true;
		}
		if (sf::Keyboard::isKeyPressed(JUMP) && canJump) {
			this->canJump = false;
			this->isJumping = true;
			this->VELOCITY.y = -this->JUMP_VELOCITY;
		}
		// if current direction is different than previous one, change it
			this->sprite.scale((facesRight != facedRight) ? -1 : 1, 1);
		// 3. this solution seems much cleaner than another while(window.pollEvent(event)) loop
		// 4. that detects if key was pressed/released	
		if (sf::Keyboard::isKeyPressed(ZOOM_IN))camera.Zoom(0.9f);
		if (sf::Keyboard::isKeyPressed(ZOOM_OUT))camera.Zoom(1.1f);
		/* equipping test 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			inventory.equipItem(ITEMS::SCYTHE, SLOTS::HAND);
		*/
	}
};

#endif