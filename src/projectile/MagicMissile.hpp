#pragma once

#include "./Projectile.hpp"

class MagicMissile : public Projectile {
private:
	float lifespan;

public:
	MagicMissile(Game* game, float speed, int damage, float lifespan);
	void update(float dt) override;
	void draw() override;
};