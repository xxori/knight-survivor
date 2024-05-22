#include "Projectile.hpp"
#include "../Game.hpp"
#include "../common/GameEntity.hpp"

void Projectile::setSpeed(float speed) { this->speed = speed; }
float Projectile::getSpeed() { return speed; }

void Projectile::setDamage(int damage) { this->damage = damage; }
int Projectile::getDamage() { return damage; }

Projectile::Projectile(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, int damage, float speed) : GameEntity(game, pos, collider), speed(speed), damage(damage) {}

void Projectile::update(float dt) {
	// Check collissions with all the enemies to damage them
	for (auto enemy : getGame()->getEnemies()) {
		if (enemy != NULL && enemy->collide(this))
			enemy->takeDamage(damage, this);
	}

	// If the projectile is off the screen, delete it
	raylib::Vector2 playerPos = getGame()->getPlayer()->getPos();
	if (abs(getPos().x - playerPos.x) > SCREEN_WIDTH / 2.0 || abs(getPos().y - playerPos.y) > SCREEN_HEIGHT / 2.0)
		getGame()->removeObject(this);
}