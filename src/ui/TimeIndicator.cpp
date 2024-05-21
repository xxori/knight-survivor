#include "TimeIndicator.hpp"
#include "../Game.hpp"
#include <format>
#include <raylib.h>

TimeIndicator::TimeIndicator(Game* game) : Text(game, "Time: ", raylib::Vector2(0, 0), 36, DARKGREEN) {}

void TimeIndicator::update(float dt) {
	// We don't care about fractional seconds, so we cast to int
	int hseconds = static_cast<int>(getGame()->getHighScore());
	int seconds = static_cast<int>(getGame()->getTime());
	// If our current time is the highscore, we don't need to repeat it
	if (hseconds > seconds) {
		setText(std::format("Time: {}:{:02}\n\nHighscore: {}:{:02}", seconds / 60, seconds % 60, hseconds / 60, hseconds % 60));
	} else {
		setText(std::format("Time: {}:{:02}", seconds / 60, seconds % 60));
	}
	// This element is placed in the top right of the screen
	setPos(raylib::Vector2(SCREEN_WIDTH - 10 - MeasureText(getText().c_str(), 36), 10));
}