#include "GameObject.hpp"

GameObject::GameObject(Game* game, raylib::Vector2 pos) : game(game), pos(pos) {}

GameObject::~GameObject() {}

raylib::Vector2 GameObject::getPos() { return pos; }
void GameObject::setPos(raylib::Vector2 pos) { this->pos = pos; }
Game* GameObject::getGame() { return game; }
