#include <SFML/Graphics.hpp>
#include "Event.hpp"
#include "Window.hpp"
#include "Constants.hpp"
#pragma once

namespace GLOBAL {
	Event EVENT;
	Window game(CONSTANTS::WINDOW_SIZE, "Lost Soul", CONSTANTS::FRAMERATE);
	Window debug(CONSTANTS::WINDOW_SIZE, "Debug Mode", CONSTANTS::FRAMERATE);
	Window op(CONSTANTS::WINDOW_SIZE, "Operator Mode", CONSTANTS::FRAMERATE);
}
