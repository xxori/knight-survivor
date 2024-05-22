#pragma once

#include "Text.hpp"

// The HUD element showing current time and highscore time.
class TimeIndicator : public Text {
public:
	TimeIndicator(Game* game);
	void update(float dt) override;
};