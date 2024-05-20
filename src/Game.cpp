#include "Game.hpp"
#include "Background.hpp"
#include "enemy/Enemy.hpp"
#include "enemy/Goblin.hpp"
#include "ui/Button.hpp"
#include "ui/FPSCounter.hpp"
#include "ui/HealthCount.hpp"
#include "ui/XPLevelIndicator.hpp"
#include <algorithm>
#include <raylib-cpp.hpp>
#include <raylib.h>

// Initialise empty vectors, add critical entities like player, Background, FPS Counter
// These addings could be broken out to a i.e. UI Manager class
Game::Game() : enemies(), objects(), playingUI(), mainMenu(), pauseMenu(), deadMenu(), state(MainMenu), escapePressedLastFrame(false), time(0), lastTime(0) {
	background = new Background(this, 25);
	addUIObject(new FPSCounter(this));
	addUIObject(new HealthCount(this));
	addUIObject(new XPLevelIndicator(this));
	player = new Player(this);

	// Load font
#ifndef BUILD_TEST_RUNNER

	font = raylib::Font("../res/Romulus.ttf", 64, 0, 350);

#endif

	// Main menu items
	mainMenu.push_back(new Text(this, "Knight Survivors", raylib::Vector2(175, 100), 50, RED));
	mainMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Playing); }, raylib::Vector2(200, 200), RED, BLUE, "Play", 12, 36, WHITE));
	mainMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Tutorial); }, raylib::Vector2(400, 200), RED, BLUE, "Tutorial", 12, 36, WHITE));

	// Tutorial menu items
	tutorialMenu.push_back(new Text(this, "Avoid enemies and stay alive for as long as possible!", raylib::Vector2(125, 100), 20, RED));
	tutorialMenu.push_back(new Text(this, "Use WASD or arrow keys to move around", raylib::Vector2(175, 125), 20, RED));
	tutorialMenu.push_back(new Text(this, "Avoid colliding with enemies, as this will make you lose health", raylib::Vector2(100, 150), 20, RED));
	tutorialMenu.push_back(new Button(
			this, [](Game* game) { game->setState(MainMenu); }, raylib::Vector2(350, 250), RED, BLUE, "Back", 12, 36, WHITE));

	// Dead menu items
	deadMenu.push_back(new Text(this, "You died!", raylib::Vector2(325, 100), 30, RED));
	deadMenu.push_back(new Button(
			this, [](Game* game) { game->resetObjects(); game->getPlayer()->resetWeapons(game); game->getPlayer()->resetHealth(); game->resetEnemy(); game->setState(Playing); }, raylib::Vector2(310, 250), RED, BLUE, "Respawn", 12, 36, WHITE));

	// Pause menu items
	pauseMenu.push_back(new Text(this, "Paused", raylib::Vector2(310, 100), 54, RED));
	pauseMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Confirmation); }, raylib::Vector2(450, 250), RED, BLUE, "Quit", 12, 36, WHITE));
	pauseMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Playing); }, raylib::Vector2(270, 250), RED, BLUE, "Back", 12, 36, WHITE));
	pauseMenu.push_back(new Button(
			this, [](Game* game) { game->setState(MainMenu); }, raylib::Vector2(300, 350), RED, BLUE, "Main Menu", 12, 36, WHITE));

	// Confirmation menu items
	confirmationMenu.push_back(new Text(this, "Are you sure you want to quit?", raylib::Vector2(150, 100), 30, RED));
	confirmationMenu.push_back(new Button(
			this, [](Game* game) { CloseWindow(); }, raylib::Vector2(420, 200), RED, BLUE, "YES", 12, 36, WHITE));
	confirmationMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Paused); }, raylib::Vector2(270, 200), RED, BLUE, "NO", 12, 36, WHITE));
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

	GameState s = state;
	switch (s) {
		case MainMenu:
			for (auto uiEntity : mainMenu) {
				uiEntity->update(dt);
			}
			break;

		case Paused:
			for (auto uiEntity : pauseMenu) {
				uiEntity->update(dt);
			}
			if (IsKeyDown(KEY_ESCAPE) && !escapePressedLastFrame) setState(Playing);
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
			if (IsKeyDown(KEY_ESCAPE)) setState(MainMenu);
			break;

		case Confirmation:
			for (auto uiEntity : confirmationMenu) {
				uiEntity->update(dt);
			}
			if (IsKeyDown(KEY_ESCAPE) && !escapePressedLastFrame) setState(Paused);
			break;

		case Playing:
			Goblin::spawn(this, dt);
			player->update(dt);
			time += dt;
			if (time >= 15 && lastTime < 15) {
				Goblin::spawnCooldown = 1.5f;
				Goblin::speed = 60;
			}
			if (time >= 30 && lastTime < 30) {
				Goblin::spawnCooldown = 1.0f;
				Goblin::speed = 70;
			}
			if (time >= 45 && lastTime < 60) {
				Goblin::spawnCooldown = 0.75f;
				Goblin::speed = 90;
			}
			if (time >= 60 && lastTime < 60) {
				Goblin::spawnCooldown = 0.5f;
				Goblin::speed = 100;
			}
			lastTime = time;
			for (auto enemy : enemies)
				enemy->update(dt);
			enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
			for (size_t i = 0; i < objects.size(); i++) {
				objects[i]->update(dt);
			}
			objects.erase(std::remove(objects.begin(), objects.end(), nullptr), objects.end());
			for (auto uEntity : playingUI) {
				uEntity->update(dt);
			}
			if (IsKeyDown(KEY_ESCAPE) && !escapePressedLastFrame) setState(Paused);
			break;
	}

	escapePressedLastFrame = IsKeyDown(KEY_ESCAPE);
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

		case Confirmation:
			for (auto uiEntity : confirmationMenu) {
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
		*it = nullptr;
	}
	delete obj;
}

void Game::addObject(GameObject* obj) {
	objects.push_back(obj);
}

raylib::Font* Game::getFont() { return &font; }

void Game::removeObject(GameObject* obj) {
	auto it = std::find(objects.begin(), objects.end(), obj);
	if (it != objects.end()) {
		*it = nullptr;
	}
	delete obj;
}

void Game::addUIObject(GameObject* obj) {
	playingUI.push_back(obj);
}

void Game::resetEnemy() {
	time = 0;
	Goblin::spawnCooldown = 3.0f;
	Goblin::speed = 50;
	for (auto enemy : enemies) {
		delete enemy;
	}
	enemies = {};
}

void Game::resetObjects() {
	for (auto obj : objects) {
		delete obj;
	}
	objects = {};
}