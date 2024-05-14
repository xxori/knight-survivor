#pragma once

#include "GameObject.hpp"

class GameEntity : public GameObject {
private:
	raylib::Texture* texture;
	raylib::Rectangle localCollider;

public:
	GameEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture);
	~GameEntity() override;
	raylib::Rectangle getCollider();
	void setCollider(raylib::Rectangle collider);
	bool collide(GameEntity* other);
	raylib::Vector2 getCenter();
};