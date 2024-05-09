#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ExitCodes.hpp"
#include "Constants.hpp"
#include "Ground.hpp"
#include "Effect.hpp"
#include "Triple.hpp"
class Entity {
public:
	unsigned int health = 9999;
	unsigned int insanity = 0;
	sf::FloatRect boundingBox;
	Entity(std::string pathToTexture, sf::IntRect txt, sf::Vector2f scale, int iframes = 30) {
		gravity = true;
		texture.loadFromFile(pathToTexture, txt);
		sprite.setTexture(texture);
		sprite.setScale(scale);
		boundingBox = sprite.getGlobalBounds();
		IMMUNITYFRAMES = iframes;
	}
	virtual void Update(sf::RenderWindow& window) {
		boundingBox.left = sprite.getPosition().x;
		boundingBox.top = sprite.getPosition().y;
	}
	virtual int onHit(Entity* Target) {
		if (!Target->isMortal()) return 0;
		Target->dealDamage(damage);
		Target->immunityFrames();
	}
	virtual EXIT_CODE draw(sf::RenderWindow& window) {
		if (NULL == sprite.getTexture()) return EXIT_CODE::RETURNED_NULL;
		window.draw(sprite);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	sf::Sprite* getSprite() {
		return &this->sprite;
	}
	sf::Texture* getTexture() {
		return &this->texture;
	}
	virtual void dealDamage(int dmg) {
		this->health -= dmg;
	}
	bool isMortal() const {
		return this->mortal;
	}
	void dealKnockback(short direction) {
		sprite.move(-1 * ((direction * CONSTANTS::BASE_SPEED.x) - 0.5f), 0.3f);
	}
	int getHealth() const {
		return this->health;
	}
	bool affectedByGravity() const {
		return this->gravity;
	}
	bool isDead() const {
		return this->health > 0;
	}
	void manageEffects(Triple<int, int, bool> triple, Effect* effect) {
		if (triple.getFirst() == 1) this->insanity += triple.getSecond();
		else if (triple.getFirst() == 10) this->health += triple.getSecond();

		if (!triple.getThird()) removeEffect(effect);
	}
	void removeEffect(Effect* effectToRemove) {
		auto iter = std::remove_if(this->currentEffects.begin(), this->currentEffects.end(),
			[effectToRemove](Effect* effect) {
				return effect == effectToRemove;
			});
		if (iter != this->currentEffects.end()) {
			std::cout << "Effect found and removed." << std::endl;
			this->currentEffects.erase(iter, this->currentEffects.end());
		}
		else {
			std::cout << "Effect not found." << std::endl;
		}
	}
	EXIT_CODE gravityForce() {
		if (!this->affectedByGravity()) return EXIT_CODE::NOT_AFFECTED_BY_GRAVITY;
		this->sprite.move(0, 2.5f * CONSTANTS::GRAVITY);
		while (Ground::collision_with_ground(this->sprite) == EXIT_CODE::SPRITE_COLLIDED) {
			this->sprite.move(0, -0.1f);
		}
		return EXIT_CODE::RETURNED_NULL;
	}
	~Entity() {
	}
	EXIT_CODE setPosition(sf::Vector2f p) {
		this->sprite.setPosition(p.x, p.y);
		return EXIT_CODE::OPERATION_SUCCESFUL;
	}
	sf::Vector2f position() {
		return this->sprite.getPosition();
	}
	sf::FloatRect l_getBounds() {
		return this->sprite.getLocalBounds();
	}
	sf::FloatRect g_getBounds() {
		return this->sprite.getGlobalBounds();
	}
	void immunityFrames() {
		(immunity_frames <= IMMUNITYFRAMES) ? this->mortal = false : this->mortal = true;
		(immunity_frames > IMMUNITYFRAMES) ? immunity_frames = 0 : immunity_frames++;
	}
	void immunityFrames(int iframes) {
		(immunity_frames <= iframes) ? this->mortal = false : this->mortal = true;
		(immunity_frames > iframes) ? immunity_frames = 0 : immunity_frames++;
	}
	/// <summary>
	/// Adds effect to entity
	/// Example player->addEffect(ptr_to_obj)
	/// </summary>
	/// <param name="ef">Pointer to effect object</param>
	void addEffect(Effect* ef) {
		currentEffects.push_back(ef);
	}
	/// <summary>
	/// Checks if Entity has effects
	/// </summary>
	/// <returns>
	/// True if currentEffects is not empty,
	/// False otherwise
	/// </returns>
	bool hasEffects() {
		return currentEffects.empty();
	}
	bool hasEffect(Effect* effect) {
		for (Effect* e : this->currentEffects) {
			if (e == effect) return true;
		}
		return false;
	}
	bool isWeapon() { return weapon; }
	/// <summary></summary>
	/// <returns>a pointer to vector containing effects of entity</returns>
	std::vector<Effect*>* getEffectVectorPointer() {
		return &this->currentEffects;
	}
	/// <summary> </summary>
	/// <returns>vector containing effects of entity </returns>
	std::vector<Effect*> getEffectVector() {
		return this->currentEffects;
	}
	bool isPlayer() const{
		return this->player;
	}
	short getDirection() { return direction; }
	protected:
		int damage = 0;
		int immunity_frames = 0;
		int IMMUNITYFRAMES = 0;
		std::vector<Effect*> currentEffects;
		bool player = false;
		bool mortal = false;
		bool gravity = false;
		bool weapon = false;
		bool knockback = false;
		bool gotHit = false;
		short directionOld = 1;
		short direction = 1;
		sf::Sprite sprite;
		sf::Texture texture;
	};
#endif