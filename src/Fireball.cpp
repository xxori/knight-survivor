#include "Fireball.hpp"
#include "Game.hpp"
#include <cmath>

Fireball::Fireball(Game* game, float speed, int damage) : Projectile(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 5, 5), nullptr, speed, damage), r(0), theta(0) {}

void Fireball::update(float dt) {
	r += getSpeed() / 3 * dt;
	theta += getSpeed() / 20 * dt;
	raylib::Vector2 movement;

	raylib::Vector2 playerPos = getGame()->getPlayer()->getPos() + raylib::Vector2(getGame()->getPlayer()->getCollider().GetWidth() / 2, getGame()->getPlayer()->getCollider().GetHeight() / 2);
	setPos(playerPos + raylib::Vector2(r * std::cos(theta), r * std::sin(theta)));
	if (abs(getPos().x - playerPos.x) > 800 / 2.0 || abs(getPos().y - playerPos.y) > 450 / 2.0) {
		getGame()->removeProjectile(this);
	}

	// Contact collisions using parent class.
	Projectile::update(dt);
}

void Fireball::draw() {
	DrawCircleV(getPos() + raylib::Vector2(10, 10), 10, RED);
}