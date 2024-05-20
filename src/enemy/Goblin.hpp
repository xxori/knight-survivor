#pragma once

#include "Enemy.hpp"

class Goblin : public Enemy {
private:
	const static int maxHealth;
	const static int damage;
	const static float damageCooldown;
	const static float speed;
	const static raylib::Rectangle collider;
	// TODO: Replace placeholder with texture
	const static int placeholderRadius;

public:
	Goblin(Game* game);
	void update(float dt) override;
	void draw() override;

	static void spawn(Game* game, float dt);
	static float timeToSpawn;
	const static float spawnCooldown;
};