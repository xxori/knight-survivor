#include "Game.hpp"

void Game::UpdateAll() {
    dt = GetFrameTime();
    for (auto entity : entities) {
        entity->Update(dt);
    }
}

void Game::DrawAll() {
    ClearBackground(RAYWHITE);
    for (auto entity : entities) {
        entity->Draw();
    }
}

Game::Game(): entities(), dt(0){}

Game::~Game() {
    for (auto entity : entities) {
        delete entity;
    }
}

void Game::AddEntity(GameEntity *entity) {
    entities.push_back(entity);
}