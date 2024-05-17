#include "KnifeThrower.hpp"
#include "../Game.hpp"
#include "../projectile/Knife.hpp"

KnifeThrower::KnifeThrower(Game* game, float fireSpeed) : Weapon(game, "Knife Thrower", fireSpeed) {}

void KnifeThrower::update(float dt) {
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addObject(new Knife(getGame(), 200, 2, getGame()->getPlayer()->getDirection()));
	}
}