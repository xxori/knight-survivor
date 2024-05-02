#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.hpp"

// The player entity is controlled by the player and is responsible for 
// triggering pauses, spawning projectiles, dying, etc
class Player : public GameEntity {
private:
	static float speed;
	
public:
	Player(Game* game);
	void Update(float dt) override;
	void Draw() override;
};

#endif