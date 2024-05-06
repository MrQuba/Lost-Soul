#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include "Triple.hpp"
#pragma once

class Effect {
protected:
public:
	virtual Triple<int, int, bool> update() = 0;
	//virtual void clear(std::vector<Effect*>* efV) = 0;
	int duration = 0;
};
#endif