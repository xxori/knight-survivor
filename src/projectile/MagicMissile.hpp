#pragma once

#include "./Projectile.hpp"

// A magic missile that seeks out the nearest enemy
class MagicMissile : public Projectile {
private:
	// The magic missile has a set lifespan as it could
	// otherwise stay on screen forever.
	float lifespan;

public:
	MagicMissile(Game* game, float speed, int damage, float lifespan);
	void update(float dt) override;
	void draw() override;
};