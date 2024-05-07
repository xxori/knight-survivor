#include "FireStaff.hpp"
#include "Fireball.hpp"
#include "Game.hpp"

FireStaff::FireStaff(Game* game, float fireSpeed) : Weapon(game, "Fire Staff", fireSpeed) {}

void FireStaff::update(float dt) {
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addProjectile(new Fireball(getGame(), 0.005, 100));
	}
}