#pragma once

#include "../common/GameEntity.hpp"
#include "../projectile/Projectile.hpp"
#include "Vector2.hpp"

class Enemy : public GameEntity {
private:
	// std::string name;
	int health;
	int damage;
	float timeToDamage;
	float damageCooldown;
	float speed;
	Projectile* lastHit;
	raylib::Vector2 generateSpawnPosition();

public:
	Enemy(Game* game, raylib::Rectangle collider, int health, int damage, float damageCooldown, float speed);
	void takeDamage(int damage, Projectile* proj);
	int getHealth();
	int getDamage();
	void update(float dt) override;
};