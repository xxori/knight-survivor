#pragma once

#include "GameObject.hpp"

// A physical entity that exists in the world and has collision
class GameEntity : public GameObject {
private:
	// A collider for the entity in local space
	raylib::Rectangle localCollider;

public:
	GameEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider);
	raylib::Rectangle getCollider();
	void setCollider(raylib::Rectangle collider);
	bool collide(GameEntity* other);
	raylib::Vector2 getCenter();
};