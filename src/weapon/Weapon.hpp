#pragma once

// Forward declaration of class to avoid circular dependency.
class Game;

// A weapon that is held by the player and regularly spawns projectiles
class Weapon {
private:
	Game* game;

	// The amount of time in seconds between weapon fires
	float fireSpeed;

	// The countdown until weapon is ready to fire again
	float timeToFire;

public:
	Weapon(Game* game, float firespeed);

	// As each weapon needs to inherit this class, it has virtual pure methods
	virtual void update(float dt) = 0;
	virtual ~Weapon();

	float getFireSpeed();
	void setFireSpeed(float speed);
	float getTimeToFire();
	void setTimeToFire(float timeToFire);

	Game* getGame();
};