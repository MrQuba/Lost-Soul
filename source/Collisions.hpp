#include <SFML/Graphics.hpp>
#include <typeinfo>
#pragma once

class Collisions {
public:
	/// <summary>
	/// Checks if sprite intersect if so calls onHit() function of object
	/// </summary>
	/// <param name="ent">Attacking entity</param>
	/// <param name="ent2">Entity that is attacked</param>
	/// <returns>true if they colided</returns>
	static bool isHit(Entity* ent, Entity* ent2) {
		if (spritesIntersect(ent, ent2) && ent != ent2) {
			if ((ent->isPlayer() || ent->isWeapon()) && (ent2->isPlayer() || ent2->isWeapon())) return false;
			std::cout << typeid(*ent).name() << " collides with: " << typeid(*ent2).name() << std::endl;
			//std::cout << typeid(*ent).name() << " position: " << ent->position().x << std::endl;
			//std::cout << typeid(*ent2).name() << " position: " << ent2->position().x << std::endl;
			ent->onHit(ent2);
			ent2->onHit(ent);
			return true;
		}
		return false;
	}

	static bool spritesIntersect(Entity* ent, Entity* ent2) {
		return 	(ent->boundingBox.intersects(ent2->boundingBox)) ? true : false;
	}
	static bool spritesIntersect(sf::Sprite& s1, sf::Sprite& s2) {
		if (s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
			return true;
		else return false;
	}
	static bool spritesIntersect(sf::Sprite s1, sf::RectangleShape& g1) {
		if (s1.getGlobalBounds().intersects(g1.getGlobalBounds())) {
			return true;
		}
		else return false;
	}

};