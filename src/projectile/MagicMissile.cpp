#include "MagicMissile.hpp"
#include "../Game.hpp"
#include "Projectile.hpp"

MagicMissile::MagicMissile(Game* game, float speed, int damage, float lifespan) : Projectile(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 10, 10), damage, speed), lifespan((lifespan)) {
	setPos(game->getPlayer()->getCenter());
}

void MagicMissile::update(float dt) {
	lifespan -= dt;
	if (lifespan <= 0) {
		getGame()->removeObject(this);
		return;
	}

	Enemy* e = nullptr;
	float minDist = 1000000;

	float dist;
	for (auto enemy : getGame()->getEnemies()) {
		if (enemy != nullptr && (dist = (getCenter() - enemy->getCenter()).Length()) < minDist) {
			e = enemy;
			minDist = dist;
		}
	}

	if (e != nullptr) {
		raylib::Vector2 dir = (e->getPos() - getPos()).Normalize();
		setPos(getPos() + dir * dt * getSpeed());
	}
	Projectile::update(dt);
}

void MagicMissile::draw() {
	DrawCircleV(getPos() + raylib::Vector2(7, 7), 7, PURPLE);
}