#include "MissileBook.hpp"
#include "../Game.hpp"
#include "../projectile/MagicMissile.hpp"

MissileBook::MissileBook(Game* game, float fireSpeed) : Weapon(game, fireSpeed) {}

void MissileBook::update(float dt) {
	// Spawn in a magic missile when cooldown is finished
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addObject(new MagicMissile(getGame(), 100, 3, 7));
	}
}