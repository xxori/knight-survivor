#pragma once

#include "../common/GameEntity.hpp"
#include "../projectile/Projectile.hpp"
#include "Vector2.hpp"

// A generic enemy class that moves towards and damages the player
class Enemy : public GameEntity {
private:
	int health;
	int damage;

	// Similar to the player, enemies have an invincibility period
	float timeToDamage;
	float damageCooldown;

	float speed;

	// We don't want the invincibilty to apply to different projectiles,
	// so we store pointer to the last hit projectile
	Projectile* lastHit;

	// We want enemies to spawn in a circle around the player
	raylib::Vector2 generateSpawnPosition();

public:
	Enemy(Game* game, raylib::Rectangle collider, int health, int damage, float damageCooldown, float speed);
	void takeDamage(int damage, Projectile* proj);
	int getHealth();
	int getDamage();
	void update(float dt) override;
};