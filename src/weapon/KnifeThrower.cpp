#include "KnifeThrower.hpp"
#include "../Game.hpp"
#include "../projectile/Knife.hpp"

KnifeThrower::KnifeThrower(Game* game, float fireSpeed) : Weapon(game, fireSpeed) {}

void KnifeThrower::update(float dt) {
	// Spawn in a knife when cooldown is finished
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addObject(new Knife(getGame(), 150 + getGame()->getPlayer()->getSpeed(), 3, -getGame()->getPlayer()->getDirection()));
	}
}