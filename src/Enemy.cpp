#include "Enemy.hpp"
#include "Game.hpp"
#include "Vector2.hpp"

Enemy::Enemy(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed) : GameEntity(game, pos, collider, texture), health(health), damage(damage), damageCooldown(damageCooldown), timeToDamage(damageCooldown), speed(speed) {}

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