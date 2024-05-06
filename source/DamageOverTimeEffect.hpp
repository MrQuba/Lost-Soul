#include <SFML/Graphics.hpp>
#include "Effect.hpp"
#include "Entity.hpp"
#pragma once

class DamageOverTimeEffect : protected Effect {
protected: 
	int health = 0;
public:
	// dmg < 0 for damaging entity
	// dmg > 0 for healing entity
	void setDamage(int dmg) {
		this->health = dmg;
	}
	virtual void update(Entity* ent) {

	}
};
