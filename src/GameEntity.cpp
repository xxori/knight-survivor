#include "GameEntity.hpp"

GameEntity::GameEntity(Game* game) : game(game) {}
void GameEntity::update(float dt) {}
void GameEntity::draw() {}
raylib::Vector2 GameEntity::getPos() { return pos; }
void GameEntity::setPos(raylib::Vector2 pos) { this->pos = pos; }
Game* GameEntity::getGame() { return game; }