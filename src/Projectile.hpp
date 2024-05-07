#pragma once

#include "GameEntity.hpp"

class Projectile : public GameEntity {
private:
	int damage;
	float speed;

public:
	Projectile(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* tex, int damage, float speed);
	int getDamage();
	void setDamage(int damage);
	float getSpeed();
	void setSpeed(float speed);

	void update(float dt);
};