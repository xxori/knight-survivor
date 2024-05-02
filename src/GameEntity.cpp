#include "GameEntity.hpp"

GameEntity::GameEntity(Game* game) : game(game) {}
void GameEntity::Update(float dt) {}
void GameEntity::Draw() {}
raylib::Vector2 GameEntity::get_pos() { return pos; }
void GameEntity::set_pos(raylib::Vector2 pos) { this->pos = pos; }
Game* GameEntity::get_game() { return game; }