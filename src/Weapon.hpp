#pragma once

#include <string>

class Game;

class Weapon {
private:
	std::string name;
	float fireSpeed;
	float timeToFire;
	Game* game;

public:
	Weapon(Game* game, std::string name, float firespeed);
	virtual void update(float dt) = 0;
	virtual ~Weapon();

	std::string getName();
	void setName(std::string name);
	float getFireSpeed();
	void setFireSpeed(float speed);
	float getTimeToFire();
	void setTimeToFire(float timeToFire);

	Game* getGame();
};