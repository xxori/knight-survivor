#include "Enemy.hpp"
#include "../Coin.hpp"
#include "../Game.hpp"
#include "../ui/DamageText.hpp"
#include "Vector2.hpp"

raylib::Vector2 Enemy::generateSpawnPosition() {
	double angle = GetRandomValue(0, 360) * PI / 180.0;
	raylib::Vector2 dir = raylib::Vector2(SCREEN_WIDTH / 2.0 * cos(angle), SCREEN_WIDTH / 2.0 * sin(angle));
	return this->getGame()->getPlayer()->getPos() + dir;
}

Enemy::Enemy(Game* game, raylib::Rectangle collider, int health, int damage, float damageCooldown, float speed) : GameEntity(game, raylib::Vector2(0, 0), collider), health(health), damage(damage), damageCooldown(damageCooldown), timeToDamage(damageCooldown), speed(speed), lastHit(nullptr) {
	this->setPos(this->generateSpawnPosition());
}

void Enemy::takeDamage(int damage, Projectile* proj) {
	if (timeToDamage <= 0 || lastHit != proj) {
		getGame()->addObject(new DamageText(getGame(), damage, getPos() + raylib::Vector2(getCollider().width, 0)));
		health -= damage;
		timeToDamage = damageCooldown;
	}
	lastHit = proj;
}
void Enemy::update(float dt) {
	if (health <= 0) {
		getGame()->addObject(new Coin(getGame(), getPos()));
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