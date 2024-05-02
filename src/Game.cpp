#include "Game.hpp"
#include "Background.hpp"
#include "FPSCounter.hpp"
#include <raylib.h>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : entities(), ui_entities(), dt(0) {
	AddEntity(new Background(this, 25));
	AddUIEntity(new FPSCounter(this));
	player = new Player(this);
}

// Dealloc all game entities
Game::~Game() {
	for (auto entity : entities) {
		delete entity;
	}
	for (auto uentity : ui_entities) {
		delete uentity;
	}
	delete player;
}

// Calculate dt, tick all entities
// TODO: Consider precedence of ticking i.e. should monsters be ticked before player, etc
void Game::UpdateAll() {
	dt = GetFrameTime();
	player->Update(dt);
	for (auto entity : entities) {
		entity->Update(dt);
	}
	for (auto uentity : ui_entities) {
		uentity->Update(dt);
	}
}

// Draw all elements, in order of first added drawn on bottom
// All UI elements are drawn on top of all game elements
// Game elements are drawn using perspective camera
void Game::DrawAll(raylib::Camera2D camera) {
	BeginDrawing();
	ClearBackground(WHITE);
	BeginMode2D(camera);
	for (auto entity : entities) {
		entity->Draw();
	}
	player->Draw();
	EndMode2D();
	for (auto uentity : ui_entities) {
		uentity->Draw();
	}
	EndDrawing();
}

Player* Game::get_player() { return player; }

void Game::AddEntity(GameEntity* entity) {
	entities.push_back(entity);
}

void Game::AddUIEntity(GameEntity* entity) {
	ui_entities.push_back(entity);
}