#include <SFML/Graphics.hpp>
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
		if (spritesIntersect(*ent->getSprite(), *ent2->getSprite())) {
			ent->onHit(ent2);
			ent2->onHit(ent);
			return true;
		}
	}

	static bool spritesIntersect(sf::Sprite& s1, sf::Sprite& s2) {
		if (s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
			return true;
		else return false;
	}
	static bool spritesIntersect(sf::Sprite s1, sf::RectangleShape& g1) {
		if (s1.getGlobalBounds().intersects(g1.getGlobalBounds())) {
			printf("true");
			return true;
		}
		else return false;
	}
	static bool spritesIntersectWithCollision(sf::Sprite& s1, sf::Sprite& s2) {
		if (spritesIntersect(s1, s2)) {
			sf::Vector2f s1pos = s1.getPosition();
			sf::Vector2f s2pos = s2.getPosition();
			sf::FloatRect s1b = s1.getLocalBounds();
			sf::FloatRect s2b = s2.getLocalBounds();
			sf::Vector2f d_x;
			sf::Vector2f d_y;
			d_x.x = s1pos.x - s2pos.x;
			d_x.y = (s1pos.x + s1b.width) + (s2pos.x + s2b.width);

			return true;
		}
		return false;
	}

};