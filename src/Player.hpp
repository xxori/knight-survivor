#pragma once

#include "GameEntity.hpp"

// The player entity is controlled by the player and is responsible for
// triggering pauses, spawning projectiles, dying, etc
class Player : public GameEntity {
private:
	float speed;
	int health;

public:
	Player(Game* game);
	void update(float dt) override;
	void draw() override;
	void takeDamage(int damage);
};
