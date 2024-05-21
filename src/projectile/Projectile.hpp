#pragma once

#include "../common/GameEntity.hpp"

// A generic projectile that flies around the screen and deals damage to enemies
class Projectile : public GameEntity {
private:
	int damage;
	float speed;

public:
	Projectile(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, int damage, float speed);
	int getDamage();
	void setDamage(int damage);
	float getSpeed();
	void setSpeed(float speed);

	void update(float dt);
};