#pragma once

#include "GameEntity.hpp"
#include "Vector2.hpp"

class Enemy : public GameEntity {
private:
	// std::string name;
	int health;
	int damage;
	float timeToDamage;
	float damageCooldown;
	float speed;
	raylib::Vector2 generateSpawnPosition();

public:
	Enemy(Game* game, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed);
	void takeDamage(int damage);
	int getHealth();
	int getDamage();
	void update(float dt) override;
};