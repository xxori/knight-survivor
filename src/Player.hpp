#pragma once

#include "common/GameEntity.hpp"
#include "weapon/Weapon.hpp"
#include <vector>

// The player entity is controlled by the player and is responsible for
// triggering pauses, spawning projectiles, dying, etc
class Player : public GameEntity {
private:
	float speed;
	int health;
	std::vector<Weapon*> weapons;
	float timeToDamage;
	float invincibility;

public:
	Player(Game* game);
	~Player();
	void update(float dt) override;
	void draw() override;
	void takeDamage(int damage);
};
