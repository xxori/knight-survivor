#pragma once

#include "GameObject.hpp"

class GameEntity : public GameObject {
private:
	raylib::Texture* texture;
	raylib::Rectangle localCollider;

public:
	GameEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture);
	raylib::Rectangle getCollider();
	void setCollider(raylib::Rectangle collider);
	bool collide(GameEntity* other);
	virtual void draw() = 0;
};