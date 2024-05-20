#pragma once

#include "Text.hpp"

class XPLevelIndicator : public Text {
public:
	XPLevelIndicator(Game* game);
	void update(float dt) override;
};