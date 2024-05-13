#include "GameEntity.hpp"
#include "Game.hpp"
#include "Rectangle.hpp"
#include "Vector2.hpp"

GameEntity::GameEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture) : localCollider(collider), GameObject(game, pos), texture(texture) {}

GameEntity::~GameEntity() {
	if (texture != nullptr) {
		delete texture;
	}
}

raylib::Rectangle GameEntity::getCollider() {
	raylib::Rectangle c = localCollider;
	c.SetPosition(raylib::Vector2(getPos().GetX() + localCollider.GetX(), getPos().GetY() + localCollider.GetY()));
	return c;
}

bool GameEntity::collide(GameEntity* other) {
	raylib::Rectangle me = getCollider();
	raylib::Rectangle them = other->getCollider();
	return me.CheckCollision(them);
}