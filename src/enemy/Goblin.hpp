#pragma once

#include "Enemy.hpp"

// A simple goblin enemy that moves in a straight line towards the player
class Goblin : public Enemy {
private:
	const static int maxHealth;
	const static int damage;
	const static float damageCooldown;
	const static raylib::Rectangle collider;
	const static int placeholderRadius;

public:
	Goblin(Game* game);
	void update(float dt) override;
	void draw() override;

	static void spawn(Game* game, float dt);
	static float speed;
	static float timeToSpawn;
	static float spawnCooldown;
};