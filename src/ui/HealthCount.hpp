#pragma once

#include "Text.hpp"

class HealthCount : public Text {
public:
	HealthCount(Game* game);
	void update(float dt) override;
};