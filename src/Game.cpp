#include "Game.hpp"
#include "Background.hpp"
#include "Button.hpp"
#include "Enemy.hpp"
#include "FPSCounter.hpp"
#include "Goblin.hpp"
#include <raylib-cpp.hpp>
#include <algorithm>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), objects(), playingUI(), mainMenu(), pauseMenu(), deadMenu(), state(MainMenu) {
	background = new Background(this, 25);
	addUIObject(new FPSCounter(this));
	player = new Player(this);

	// TODO: Add all the menu ui items here
	mainMenu.push_back(new Button(this, [](Game* game) { game->setState(Playing); }, raylib::Vector2(200, 200), RED, BLUE, "Play", 12, 36, WHITE));
}

void Game::setState(GameState state) {
	this->state = state;
}

// Dealloc all game entities
Game::~Game() {
	delete background;
	for (auto x : enemies) {
		delete x;
	}
	for (auto x : objects) {
		delete x;
	}
	for (auto x : playingUI) {
		delete x;
	}
	for (auto x : mainMenu) {
		delete x;
	}
	for (auto x : pauseMenu) {
		delete x;
	}
	for (auto x : deadMenu) {
		delete x;
	}
	delete player;
}

// Calculate dt, tick all entities
// TODO: Consider precedence of ticking i.e. should monsters be ticked before player, etc
void Game::updateAll() {
	float dt = GetFrameTime();

	switch (state) {
		case MainMenu:
			for (auto uiEntity : mainMenu) {
				uiEntity->update(dt);
			}
			break;

		case Paused:
			for (auto uiEntity : pauseMenu) {
				uiEntity->update(dt);
			}
			break;

		case Dead:
			for (auto uiEntity : deadMenu) {
				uiEntity->update(dt);
			}
			break;

		case Playing:
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
			for (auto uEntity : playingUI) {
				uEntity->update(dt);
			}
			if (IsKeyDown(KEY_ESCAPE)) {
				setState(Paused);
			}
			break;
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
	switch (state) {
		case MainMenu:
			for (auto uiEntity : mainMenu) {
				uiEntity->draw();
			}
			break;

		case Paused:
			for (auto uiEntity : pauseMenu) {
				uiEntity->draw();
			}
			break;

		case Dead:
			for (auto uiEntity : deadMenu) {
				uiEntity->draw();
			}
			break;

		case Playing:
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
			for (auto uentity : playingUI) {
				uentity->draw();
			}

			// Uncomment to show middle of screen
			// DrawRectangle(0, 450 / 2, 800, 1, GREEN);
			// DrawRectangle(800 / 2, 0, 1, 450, GREEN);

			break;
	}
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
	playingUI.push_back(obj);
}