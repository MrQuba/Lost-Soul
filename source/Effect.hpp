#pragma once

class Effect {
protected:
public:
	virtual void update() = 0;
	virtual ~Effect();
};