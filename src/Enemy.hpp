#pragma once

#include "GameEntity.hpp"

class Enemy : public GameEntity {
private:
	// std::string name;
	int health;
	int damage;
	float timeToDamage;
	float damageCooldown;
	float speed;

public:
	Enemy(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed);
	void takeDamage(int damage);
	int getHealth();
	int getDamage();
	void update(float dt) override;
};