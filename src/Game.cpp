#include "Game.hpp"
#include "Background.hpp"
#include "FPSCounter.hpp"
#include <raylib-cpp.hpp>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), projectiles(), uiObjects() {
	addEnemy(new Background(this, 25));
	addUIObject(new FPSCounter(this));
	player = new Player(this);
}

// Dealloc all game entities
Game::~Game() {
	for (auto entity : enemies) {
		delete entity;
	}
	for (auto entity : projectiles) {
		delete entity;
	}
	for (auto uentity : uiObjects) {
		delete uentity;
	}
	delete player;
}

// Calculate dt, tick all entities
// TODO: Consider precedence of ticking i.e. should monsters be ticked before player, etc
void Game::updateAll() {
	float dt = GetFrameTime();
	player->update(dt);
	for (auto entity : enemies) {
		entity->update(dt);
	}
	for (auto entity : projectiles) {
		entity->update(dt);
	}
	for (auto uEntity : uiObjects) {
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
	for (auto entity : enemies) {
		entity->draw();
	}
	for (auto entity : projectiles) {
		entity->draw();
	}
	player->draw();
	EndMode2D();
	for (auto uentity : uiObjects) {
		uentity->draw();
	}
	EndDrawing();
}

Player* Game::getPlayer() { return player; }

void Game::addEnemy(GameObject* obj) {
	enemies.push_back(obj);
}

void Game::addProjectile(GameObject* obj) {
	projectiles.push_back(obj);
}

void Game::addUIObject(GameObject* obj) {
	uiObjects.push_back(obj);
}