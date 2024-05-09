#include "Effect.hpp"
#include "OverTimeEffect.hpp"
#include "Entity.hpp"
#include "Global.hpp"
#include "Constants.hpp"
#include "InstantEffect.hpp"
#pragma once
namespace Effects {
	OverTimeEffect insanity(5, 1, 1);
	OverTimeEffect poison(5, -1, 10);
	InstantEffect heal_insanity(-2, 1);
}