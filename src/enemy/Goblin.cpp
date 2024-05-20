#include "Goblin.hpp"
#include "../Game.hpp"
#include "Rectangle.hpp"
#include <raylib.h>

const int Goblin::placeholderRadius = 15;

const int Goblin::maxHealth { 10 };
const int Goblin::damage { 1 };
const float Goblin::damageCooldown { 0.3 };
float Goblin::speed { 50 };
const raylib::Rectangle Goblin::collider { -placeholderRadius + 3, -placeholderRadius + 3, placeholderRadius * 2 - 6, placeholderRadius * 2 - 6 };

Goblin::Goblin(Game* game) : Enemy(game, collider, maxHealth, damage, damageCooldown, speed) {}

void Goblin::spawn(Game* game, float dt) {
	Goblin::timeToSpawn -= dt;
	if (Goblin::timeToSpawn <= 0) {
		game->addEnemy(new Goblin(game));
		Goblin::timeToSpawn = Goblin::spawnCooldown;
	}
}

void Goblin::update(float dt) {
	Enemy::update(dt);
}

void Goblin::draw() {
	DrawCircleV(getPos(), 15, BLUE);
}

float Goblin::timeToSpawn = 0.0f;
float Goblin::spawnCooldown = 3.0f;