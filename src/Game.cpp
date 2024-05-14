#include "Game.hpp"
#include "Background.hpp"
#include "Enemy.hpp"
#include "FPSCounter.hpp"
#include "Goblin.hpp"
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
	for (auto entity : enemies) {
		if (entity != NULL)
			entity->update(dt);
	}
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy* i) { return i == NULL; }), enemies.end());
	for (auto entity : objects) {
		if (entity != NULL) {
			entity->update(dt);
		}
	}
	objects.erase(std::remove_if(objects.begin(), objects.end(), [](GameObject* i) { return i == NULL; }), objects.end());
	for (auto uEntity : uiObjects) {
		if (uEntity != NULL)
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
		if (entity != NULL)
			entity->draw();
	}
	player->draw();
	for (auto entity : objects) {
		if (entity != NULL)
			entity->draw();
	}
	EndMode2D();
	for (auto uentity : uiObjects) {
		if (uentity != NULL)
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
		if (obj != NULL) {
			delete obj;
			obj = nullptr;
		}
		*it = nullptr;
	}
}

void Game::addObject(GameObject* obj) {
	objects.push_back(obj);
}

void Game::removeObject(GameObject* obj) {
	auto it = std::find(objects.begin(), objects.end(), obj);
	if (it != objects.end()) {
		if (obj != NULL) {
			delete obj;
			obj = nullptr;
		}
		*it = nullptr;
	}
}

void Game::addUIObject(GameObject* obj) {
	uiObjects.push_back(obj);
}