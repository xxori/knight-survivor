#include "Projectile.hpp"
#include "GameEntity.hpp"

void Projectile::setSpeed(float speed) { this->speed = speed; }
float Projectile::getSpeed() { return speed; }

void Projectile::setDamage(int damage) { this->damage = damage; }
int Projectile::getDamage() { return damage; }

Projectile::Projectile(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture, int damage, float speed) : GameEntity(game, pos, collider, texture), speed(speed), damage(damage) {
}

void Projectile::update(float dt) {
	// TODO:
	// Check collissions with all the enemies to damage them
}