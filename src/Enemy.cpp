#include "Enemy.hpp"
#include "Game.hpp"
#include "Vector2.hpp"

raylib::Vector2 Enemy::generateSpawnPosition() {
	int spawnLimit { 100 };
	int spawnX;
	do {
		spawnX = GetRandomValue(-SCREEN_WIDTH / 2, SCREEN_WIDTH / 2);
	} while (-spawnLimit < spawnX && spawnX < spawnLimit);
	int spawnY;
	do {
		spawnY = GetRandomValue(-SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2);
	} while (-spawnLimit < spawnY && spawnY < spawnLimit);
	return raylib::Vector2(spawnX, spawnY);
}

Enemy::Enemy(Game* game, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed) : GameEntity(game, generateSpawnPosition(), collider, texture), health(health), damage(damage), damageCooldown(damageCooldown), timeToDamage(damageCooldown), speed(speed) {}

void Enemy::takeDamage(int damage) {
	if (timeToDamage <= 0) {
		health -= damage;
		timeToDamage = damageCooldown;
	}
	if (health <= 0) {
		getGame()->removeEnemy(this);
	}
}
void Enemy::update(float dt) {
	timeToDamage -= dt;
	raylib::Vector2 playerPos { getGame()->getPlayer()->getPos() };
	raylib::Vector2 direction { (playerPos - getPos()).Normalize() * speed * dt };
	setPos(getPos() + direction);
}
int Enemy::getHealth() {
	return health;
}
int Enemy::getDamage() {
	return damage;
}