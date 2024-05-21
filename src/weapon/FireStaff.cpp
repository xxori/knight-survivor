#include "FireStaff.hpp"
#include "../Game.hpp"
#include "../projectile/Fireball.hpp"

FireStaff::FireStaff(Game* game, float fireSpeed) : Weapon(game, fireSpeed) {}

void FireStaff::update(float dt) {
	// Spawn in a fireball when cooldown is finished
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addObject(new Fireball(getGame(), 100, 5));
	}
}