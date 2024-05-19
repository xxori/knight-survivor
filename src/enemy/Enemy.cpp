#include "Enemy.hpp"
#include "../Game.hpp"
#include "../ui/DamageText.hpp"
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
		getGame()->addObject(new DamageText(getGame(), damage, getPos() + raylib::Vector2(getCollider().width, 0)));
		health -= damage;
		timeToDamage = damageCooldown;
	}
}
void Enemy::update(float dt) {
	if (health <= 0) {
		getGame()->removeEnemy(this);
		return;
	}
	timeToDamage -= dt;
	Player* player = getGame()->getPlayer();
	raylib::Vector2 playerPos { player->getCenter() };
	raylib::Vector2 direction { (playerPos - getPos()).Normalize() * speed * dt };
	setPos(getPos() + direction);

	for (auto enemy : getGame()->getEnemies()) {
		if (enemy != NULL && enemy->collide(this)) {
			raylib::Vector2 dir = this->getCenter() - enemy->getCenter();
			setPos(getPos() + dir.Normalize() * dt * speed);
			// enemy->setPos(enemy->getPos() - dir * dt * 2.0);
		}
	}
	if (player->collide(this)) {
		player->takeDamage(damage);
		raylib::Vector2 dir = this->getCenter() - player->getCenter();
		setPos(getPos() + dir.Normalize() * dt * speed * 2.0);
	}
}

int Enemy::getHealth() {
	return health;
}
int Enemy::getDamage() {
	return damage;
}