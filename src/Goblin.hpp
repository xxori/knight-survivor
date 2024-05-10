#pragma once

#include "Enemy.hpp"

class Goblin : public Enemy {
public:
	Goblin(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed);
	void update(float dt) override;
	void draw() override;
};