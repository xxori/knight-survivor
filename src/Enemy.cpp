#include "Enemy.hpp"
#include "Game.hpp"
#include "Vector2.hpp"

raylib::Vector2 Enemy::generateSpawnPosition() {
	double angle = GetRandomValue(0, 360) * PI / 180.0;
	raylib::Vector2 dir = raylib::Vector2(SCREEN_WIDTH * cos(angle), SCREEN_WIDTH * sin(angle));
	return this->getGame()->getPlayer()->getPos() + dir;
}

Enemy::Enemy(Game* game, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed) : GameEntity(game, raylib::Vector2(0, 0), collider, texture), health(health), damage(damage), damageCooldown(damageCooldown), timeToDamage(damageCooldown), speed(speed) {
	this->setPos(this->generateSpawnPosition());
}

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