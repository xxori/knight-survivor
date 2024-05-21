#include "Weapon.hpp"

Weapon::Weapon(Game* game, float fireSpeed) : game(game), fireSpeed(fireSpeed), timeToFire(fireSpeed) {}
Weapon::~Weapon() {}

// Getters and setters to allow access in subclasses
float Weapon::getFireSpeed() { return fireSpeed; }
void Weapon::setFireSpeed(float speed) { this->fireSpeed = speed; }
float Weapon::getTimeToFire() { return timeToFire; }
void Weapon::setTimeToFire(float timeToFire) { this->timeToFire = timeToFire; }

Game* Weapon::getGame() { return game; }