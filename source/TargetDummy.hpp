#include "Entity.hpp"
#include "Global.hpp"
#include "Ground.hpp"
#include "Collisions.hpp"
#pragma once

class TargetDummy : public Entity {
public:
	TargetDummy(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale)
		: Entity(pathToTexture, txt, scale) {
		this->mortal = true;
		this->health = 99999999;
	}
	virtual void Update(sf::RenderWindow& window) override {
		gravityForce();
		for (Entity* ent : *GLOBAL::ENTITIES_SET_POINTER)
			Collisions::isHit(this, ent);
	}
	virtual int onHit(Entity* Target) override {
		this->sprite.scale(-1, 1);
		return 0;
	}
protected:
};