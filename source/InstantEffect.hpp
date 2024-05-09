#include "Effect.hpp"
#include "Triple.hpp"
#include <iostream>
#pragma once
class InstantEffect : public Effect {
public:
	InstantEffect(int change, int tochange) {
		this->duration = 0;
		this->change = change;
		this->toChange = tochange;
	}
	Triple<int, int, bool> update() override {
		return Triple<int, int, bool>(this->toChange, this->change, this->duration > 0);
	}
protected:
	int toChange;
	int change;
};
