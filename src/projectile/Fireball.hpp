#pragma once

#include "Projectile.hpp"

// A fireball that moves in a spiral around the player
class Fireball : public Projectile {
private:
	// We use polar coordinates to easily rotate and move the fireball
	float theta;
	float r;

public:
	Fireball(Game* game, float speed, int damage);
	void update(float dt) override;
	void draw() override;
};