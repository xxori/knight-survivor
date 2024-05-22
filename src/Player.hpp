#pragma once

#include "common/GameEntity.hpp"
#include "weapon/Weapon.hpp"
#include <vector>

// The player entity is controlled by the player and is responsible for
// triggering pauses, spawning projectiles, dying, etc
class Player : public GameEntity {
private:
	// The amount of units the player moves each second
	float speed;

	// Player health, reduces by 1 when hit by enemy.
	// game ends when health = 0
	int health;

	// A vector of weapons containing all of the players weapons
	// that spawn projectiles as the game goes on.
	std::vector<Weapon*> weapons;

	// We want the player to be invincible for a bit after taking damage
	// to prevent instantly dying on subsequent frames.
	// This, we store the countdown until player is vulnerable as
	// well as the maximum invincibility time.
	float timeToDamage;
	float invincibility;

	// This is the direction the player most recently moved in,
	// used in the Knife weapon which shoots out straight.
	raylib::Vector2 direction;

	// The players level increases when their experience hits 5*level.
	// On level up, the player gains health, speed, and a weapon.
	int level;
	int experience;

	// Every level up or on game start, the player gets a random weapon.
	void addRandomWeapon();

public:
	Player(Game* game);
	~Player();

	void update(float dt) override;
	void draw() override;

	void takeDamage(int damage);

	void resetStats();
	void resetWeapons(Game* game);

	int getHealth();
	int getXp();
	void setXp(int xp);
	int getLevel();
	float getSpeed();

	void setDirection(raylib::Vector2 direction);
	raylib::Vector2 getDirection();
};
