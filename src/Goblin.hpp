#pragma once

#include "Enemy.hpp"

class Goblin : public Enemy {
private:
	const static int health;
	const static int damage;
	const static float damageCooldown;
	const static float speed;
	const static raylib::Rectangle collider;
	static raylib::Texture* texture;
	// TODO: Replace placeholder with texture
	const static int placeholderRadius;

public:
	Goblin(Game* game);
	void update(float dt) override;
	void draw() override;

	static float timeToSpawn;
	const static float spawnCooldown;
};