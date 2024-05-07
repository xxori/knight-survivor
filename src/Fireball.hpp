#pragma once

#include "Projectile.hpp"

class Fireball : public Projectile {
private:
	float theta;
	float r;

public:
	Fireball(Game* game, float speed, int damage);
	void update(float dt) override;
	void draw() override;
};