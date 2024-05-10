#include "Goblin.hpp"
#include <raylib.h>

Goblin::Goblin(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed) : Enemy(game, pos, collider, texture, health, damage, damageCooldown, speed) {}

void Goblin::update(float dt) {
	Enemy::update(dt);
}

void Goblin::draw() {
	DrawCircleV(getPos(), 15, BLUE);
}