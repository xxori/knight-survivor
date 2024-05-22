#pragma once

#include "Text.hpp"

// The HUD element showing experience and level of the player
class XPLevelIndicator : public Text {
public:
	XPLevelIndicator(Game* game);
	void update(float dt) override;
};