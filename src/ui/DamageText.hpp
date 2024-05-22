#pragma once

#include "Text.hpp"

// A temporary text element that appears when an enemy takes damage
// showing how much damage was dealt.
class DamageText : public Text {
private:
	// The damage text disappears over time
	float lifespan;

public:
	DamageText(Game* game, int damage, raylib::Vector2 pos);
	DamageText(Game* game, int damage, raylib::Vector2 pos, float lifespan);

	void update(float dt) override;
};