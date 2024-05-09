#include "Game.hpp"
#include "Background.hpp"
#include "FPSCounter.hpp"
#include "Button.hpp"
#include <raylib-cpp.hpp>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), projectiles(), uiObjects() {
	addEnemy(new Background(this, 25));
	addUIObject(new FPSCounter(this));
	addUIObject(new Button(this, raylib::Vector2(10, 35), 50, 50, RED));
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
	player->draw();
	for (auto entity : projectiles) {
		entity->draw();
	}
	EndMode2D();
	for (auto uentity : uiObjects) {
		uentity->draw();
	}

	// Uncomment to show middle of screen
	// DrawRectangle(0, 450 / 2, 800, 1, GREEN);
	// DrawRectangle(800 / 2, 0, 1, 450, GREEN);

	EndDrawing();
}

Player* Game::getPlayer() { return player; }

void Game::addEnemy(GameObject* obj) {
	enemies.push_back(obj);
}

void Game::removeEnemy(GameObject* obj) {
	for (int i = 0; i < enemies.size(); i++)
		if (enemies[i] == obj)
			enemies.erase(enemies.begin() + i);
	delete obj;
	return;
}

void Game::addProjectile(Projectile* obj) {
	projectiles.push_back(obj);
}

void Game::removeProjectile(Projectile* obj) {
	for (int i = 0; i < projectiles.size(); i++)
		if (projectiles[i] == obj)
			projectiles.erase(projectiles.begin() + i);
	delete obj;
	return;
}

void Game::addUIObject(GameObject* obj) {
	uiObjects.push_back(obj);
}