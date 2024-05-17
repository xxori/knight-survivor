#pragma once

#include "Text.hpp"

class DamageText : public Text {
private:
	float lifespan;

public:
	DamageText(Game* game, int damage, raylib::Vector2 pos);
	DamageText(Game* game, int damage, raylib::Vector2 pos, float lifespan);

	void update(float dt) override;
};