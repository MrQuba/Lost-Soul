#include "Effects.hpp"
#include "Effect.hpp"
#include "Entity.hpp"
#pragma once

namespace EffectManager {
	void updateEffects(Entity* ent) {
		if (ent->hasEffects()) {
			for (Effect* ef : *ent->getEffectVectorPointer()) {
				ef->update();
			}

		}
	}
}
