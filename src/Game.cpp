#include "Game.hpp"
#include "Background.hpp"
#include "FPSCounter.hpp"
#include <raylib.h>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : entities(), uiEntities(), dt(0) {
	addEntity(new Background(this, 25));
	addUIEntity(new FPSCounter(this));
	player = new Player(this);
}

// Dealloc all game entities
Game::~Game() {
	for (auto entity : entities) {
		delete entity;
	}
	for (auto uentity : uiEntities) {
		delete uentity;
	}
	delete player;
}

// Calculate dt, tick all entities
// TODO: Consider precedence of ticking i.e. should monsters be ticked before player, etc
void Game::updateAll() {
	dt = GetFrameTime();
	player->update(dt);
	for (auto entity : entities) {
		entity->update(dt);
	}
	for (auto uEntity : uiEntities) {
		uEntity->update(dt);
	}
}

// Draw all elements, in order of first added drawn on bottom
// All UI elements are drawn on top of all game elements
// Game elements are drawn using perspective camera
void Game::drawAll(raylib::Camera2D camera) {
	BeginDrawing();
	ClearBackground(WHITE);
	BeginMode2D(camera);
	for (auto entity : entities) {
		entity->draw();
	}
	player->draw();
	EndMode2D();
	for (auto uentity : uiEntities) {
		uentity->draw();
	}
	EndDrawing();
}

Player* Game::getPlayer() { return player; }

void Game::addEntity(GameEntity* entity) {
	entities.push_back(entity);
}

void Game::addUIEntity(GameEntity* entity) {
	uiEntities.push_back(entity);
}