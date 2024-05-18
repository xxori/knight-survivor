#include "Game.hpp"
#include "Background.hpp"
#include "enemy/Enemy.hpp"
#include "enemy/Goblin.hpp"
#include "ui/Button.hpp"
#include "ui/FPSCounter.hpp"
#include <algorithm>
#include <raylib-cpp.hpp>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), objects(), playingUI(), mainMenu(), pauseMenu(), deadMenu(), state(MainMenu) {
	background = new Background(this, 25);
	addUIObject(new FPSCounter(this));
	player = new Player(this);

	// Main menu items
	mainMenu.push_back(new Text(this, "Knight Survivors", raylib::Vector2(175, 100), 50, RED));
	mainMenu.push_back(new Button(this, [](Game* game) { game->setState(Playing); }, raylib::Vector2(200, 200), RED, BLUE, "Play", 12, 36, WHITE));
	mainMenu.push_back(new Button(this, [](Game* game) { game->setState(Tutorial); }, raylib::Vector2(400, 200), RED, BLUE, "Tutorial", 12, 36, WHITE));

	// Tutorial menu items
	tutorialMenu.push_back(new Text(this, "Avoid enemies and stay alive for as long as possible!", raylib::Vector2(125, 100), 20, RED));
	tutorialMenu.push_back(new Text(this, "Use WASD or arrow keys to move around", raylib::Vector2(175, 125), 20, RED));
	tutorialMenu.push_back(new Text(this, "Avoid colliding with enemies, as this will make you lose health", raylib::Vector2(100, 150), 20, RED));
	tutorialMenu.push_back(new Button(this, [](Game* game) { game->setState(MainMenu); }, raylib::Vector2(350, 250), RED, BLUE, "Back", 12, 36, WHITE));

	// Dead menu items
	deadMenu.push_back(new Text(this, "You died!", raylib::Vector2(325, 100), 30, RED));
	deadMenu.push_back(new Button(this, [](Game* game) { game->resetObjects(); game->getPlayer()->resetWeapons(game); game->getPlayer()->resetHealth(); game->resetEnemy(); game->setState(Playing); }, raylib::Vector2(310, 250), RED, BLUE, "Respawn", 12, 36, WHITE));

	// Pause menu items
	pauseMenu.push_back(new Text(this, "Paused", raylib::Vector2(350, 100), 30, RED));
	pauseMenu.push_back(new Button(this, [](Game* game) { game->setState(Playing); }, raylib::Vector2(350, 250), RED, BLUE, "Back", 12, 36, WHITE));

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
	for (auto x : tutorialMenu) {
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

		case Tutorial:
			for (auto uiEntity : tutorialMenu) {
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

		case Tutorial:
			for (auto uiEntity : tutorialMenu) {
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

void Game::resetEnemy() {
	enemies = {};
}

void Game::resetObjects() {
	objects = {};
}