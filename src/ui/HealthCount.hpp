#pragma once

#include "Text.hpp"

// HUD element representing the player's current health
class HealthCount : public Text {
public:
	HealthCount(Game* game);
	void update(float dt) override;
};