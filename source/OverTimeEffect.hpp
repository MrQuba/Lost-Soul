#include "Effect.hpp"
#include "Triple.hpp"
#include <iostream>
#pragma once
class OverTimeEffect : public Effect {
public:
	OverTimeEffect(int duration, int change, int tochange) {
		this->duration = 60 * duration;
		this->change = change;
		this->toChange = tochange;
	}
	Triple<int, int, bool> update() override {
		if (this->duration % 20 == 0) {
			this->duration--;
			return Triple<int, int, bool>(this->toChange, this->change, this->duration > 0);
		}
		else this->duration--;
		std::cout << duration << std::endl;
		return Triple<int, int, bool>(0, 0, this->duration > 0);
	}
	//void clear(std::vector<Effect*>*efV) override {
	//		if (this->duration <= 0) {
	//			efV->erase(this);
	//		}
	//}
protected:
	int toChange;
	int change;
};
