#include "Weapon.hpp"

Weapon::Weapon(Game* game, std::string name, float fireSpeed) : game(game), name(name), fireSpeed(fireSpeed), timeToFire(fireSpeed) {}
Weapon::~Weapon() {}

std::string Weapon::getName() {
	return name;
}
void Weapon::setName(std::string name) { this->name = name; }
float Weapon::getFireSpeed() { return fireSpeed; }
void Weapon::setFireSpeed(float speed) { this->fireSpeed = speed; }
float Weapon::getTimeToFire() { return timeToFire; }
void Weapon::setTimeToFire(float timeToFire) { this->timeToFire = timeToFire; }

Game* Weapon::getGame() { return game; }