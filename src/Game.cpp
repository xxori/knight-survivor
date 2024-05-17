#include "Game.hpp"
#include "Background.hpp"
#include "enemy/Enemy.hpp"
#include "enemy/Goblin.hpp"
#include "ui/FPSCounter.hpp"
#include <raylib-cpp.hpp>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), objects(), uiObjects() {
	background = new Background(this, 25);
	addUIObject(new FPSCounter(this));
	player = new Player(this);
}

// Dealloc all game entities
Game::~Game() {
	delete background;
	for (auto entity : enemies) {
		delete entity;
	}
	for (auto entity : objects) {
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

	Goblin::spawn(this, dt);

	player->update(dt);
	for (auto enemy : enemies) {
		enemy->update(dt);
	}
	enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
	for (auto object : objects) {
		object->update(dt);
	}
	objects.erase(std::remove(objects.begin(), objects.end(), nullptr), objects.end());
	for (auto uEntity : uiObjects) {
		uEntity->update(dt);
	}
}

std::vector<Enemy*> Game::getEnemies() {
	return enemies;
}

// Draw all elements, in order of first added drawn on bottom
// All UI elements are drawn on top of all game elements
// Game elements are drawn using perspective camera
void Game::drawAll(raylib::Camera2D camera) {
	BeginDrawing();
	ClearBackground(WHITE);
	BeginMode2D(camera);
	background->draw();
	for (auto entity : enemies) {
		if (entity != nullptr)
			entity->draw();
	}
	player->draw();
	for (auto entity : objects) {
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

void Game::addEnemy(Enemy* obj) {
	enemies.push_back(obj);
}

void Game::removeEnemy(Enemy* obj) {
	auto it = std::find(enemies.begin(), enemies.end(), obj);
	if (it != enemies.end()) {
		delete obj;
		*it = nullptr;
	}
}

void Game::addObject(GameObject* obj) {
	objects.push_back(obj);
}

void Game::removeObject(GameObject* obj) {
	auto it = std::find(objects.begin(), objects.end(), obj);
	if (it != objects.end()) {
		delete obj;
		*it = nullptr;
	}
}

void Game::addUIObject(GameObject* obj) {
	uiObjects.push_back(obj);
}