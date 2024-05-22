#include "Enemy.hpp"
#include "../Coin.hpp"
#include "../Game.hpp"
#include "../ui/DamageText.hpp"
#include "Vector2.hpp"

raylib::Vector2 Enemy::generateSpawnPosition() {
	// Spawn at a random point on the circle around the player using random angle
	double angle = GetRandomValue(0, 360) * PI / 180.0;
	// The circle has diamater of SCREEN_WIDTH
	raylib::Vector2 dir = raylib::Vector2(SCREEN_WIDTH / 2.0 * cos(angle), SCREEN_WIDTH / 2.0 * sin(angle));
	return this->getGame()->getPlayer()->getPos() + dir;
}

Enemy::Enemy(Game* game, raylib::Rectangle collider, int health, int damage, float damageCooldown, float speed) : GameEntity(game, raylib::Vector2(0, 0), collider), health(health), damage(damage), damageCooldown(damageCooldown), timeToDamage(damageCooldown), speed(speed), lastHit(nullptr) {
	this->setPos(this->generateSpawnPosition());
}

void Enemy::takeDamage(int damage, Projectile* proj) {
	// If enemy is vulnerable or a new projectile is hitting,
	// spawn damagetext, lower health, and reset invincibility cooldown
	if (timeToDamage <= 0 || lastHit != proj) {
		getGame()->addObject(new DamageText(getGame(), damage, getPos() + raylib::Vector2(getCollider().width, 0)));
		health -= damage;
		timeToDamage = damageCooldown;
		lastHit = proj;

		// If health is out, spawn a new coin and remove enemy
		if (health <= 0) {
			getGame()->addObject(new Coin(getGame(), getPos()));
			getGame()->removeEnemy(this);
		}
	}
}
void Enemy::update(float dt) {
	timeToDamage -= dt;

	// Move towards player a set amount
	Player* player = getGame()->getPlayer();
	raylib::Vector2 playerPos { player->getCenter() };
	raylib::Vector2 direction { (playerPos - getPos()).Normalize() * speed * dt };
	setPos(getPos() + direction);

	// We don't want enemies to overlap, so we perform some basic collision
	for (auto enemy : getGame()->getEnemies()) {
		if (enemy != NULL && enemy->collide(this)) {
			raylib::Vector2 dir = this->getCenter() - enemy->getCenter();
			setPos(getPos() + dir.Normalize() * dt * speed);
		}
	}

	// The player should also push away enemies
	if (player->collide(this)) {
		player->takeDamage(damage);
		raylib::Vector2 dir = this->getCenter() - player->getCenter();
		setPos(getPos() + dir.Normalize() * dt * speed * 2.0);
	}
}

int Enemy::getHealth() { return health; }
int Enemy::getDamage() { return damage; }