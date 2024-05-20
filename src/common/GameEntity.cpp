#include "GameEntity.hpp"
#include "../Game.hpp"
#include "Rectangle.hpp"
#include "Vector2.hpp"

GameEntity::GameEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider) : localCollider(collider), GameObject(game, pos) {}

raylib::Rectangle GameEntity::getCollider() {
	raylib::Rectangle c = localCollider;
	c.SetPosition(raylib::Vector2(getPos().GetX() + localCollider.GetX(), getPos().GetY() + localCollider.GetY()));
	return c;
}

bool GameEntity::collide(GameEntity* other) {
	if (other == NULL)
		return false;
	raylib::Rectangle me = getCollider();
	raylib::Rectangle them = other->getCollider();
	return me.CheckCollision(them);
}

raylib::Vector2 GameEntity::getCenter() {
	return raylib::Vector2(getPos().x + getCollider().width / 2, getPos().y + getCollider().height / 2);
}