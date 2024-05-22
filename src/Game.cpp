#include "Game.hpp"
#include "Background.hpp"
#include "enemy/Enemy.hpp"
#include "enemy/Goblin.hpp"
#include "ui/Button.hpp"
#include "ui/FPSCounter.hpp"
#include "ui/HealthCount.hpp"
#include "ui/TimeIndicator.hpp"
#include "ui/XPLevelIndicator.hpp"
#include <algorithm>
#include <fstream>
#include <raylib-cpp.hpp>
#include <raylib.h>

Game::Game() : enemies(), objects(), playingUI(), mainMenu(), pauseMenu(), deadMenu(), state(MainMenu), escapePressedLastFrame(false), time(0), highScore(0) {

	// Initialise background, HUD, and player
	background = new Background(this, 25);
	playingUI.push_back(new FPSCounter(this));
	playingUI.push_back(new HealthCount(this));
	playingUI.push_back(new XPLevelIndicator(this));
	playingUI.push_back(new TimeIndicator(this));
	player = new Player(this);

#ifndef BUILD_TEST_RUNNER
	// We don't want to load Font in testrunner
	// as raylib gui window isn't loaded, so it would crash
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
			this, [](Game* game) { game->resetObjects(); game->getPlayer()->resetWeapons(game); game->getPlayer()->resetStats(); game->resetEnemy(); game->setState(Playing); }, raylib::Vector2(310, 250), RED, BLUE, "Respawn", 12, 36, WHITE));

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
			this, [](Game* game) { game->saveHighScore(); CloseWindow(); exit(0); }, raylib::Vector2(420, 200), RED, BLUE, "YES", 12, 36, WHITE));
	confirmationMenu.push_back(new Button(
			this, [](Game* game) { game->setState(Paused); }, raylib::Vector2(270, 200), RED, BLUE, "NO", 12, 36, WHITE));
}

// Getters and setters to expose internal state to game objects
void Game::setState(GameState state) { this->state = state; }

std::vector<Enemy*> Game::getEnemies() { return enemies; }

Player* Game::getPlayer() { return player; }

void Game::addObject(GameObject* obj) { objects.push_back(obj); }

raylib::Font* Game::getFont() { return &font; }

float Game::getTime() { return time; }

float Game::getHighScore() { return highScore; }

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

void Game::updateAll() {
	// Calculate deltatime using raylib
	float dt = GetFrameTime();

	GameState s = state;
	// We want to do different things in different gamestates
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
			// Process goblin spawning
			Goblin::spawn(this, dt);
			player->update(dt);
			time += dt;

			// If we have a new highscore, set it
			if (time > highScore) {
				highScore = time;
			}

			// Increase difficulty at certain times
			if (time >= 15 && time - dt < 15) {
				Goblin::spawnCooldown = 1.5f;
				Goblin::speed = 60;
			}
			if (time >= 30 && time - dt < 30) {
				Goblin::spawnCooldown = 1.0f;
				Goblin::speed = 70;
			}
			if (time >= 45 && time - dt < 60) {
				Goblin::spawnCooldown = 0.75f;
				Goblin::speed = 90;
			}
			if (time >= 60 && time - dt < 60) {
				Goblin::spawnCooldown = 0.5f;
				Goblin::speed = 100;
			}
			if (time >= 120 && time - dt < 120) {
				Goblin::spawnCooldown = 0.25f;
				Goblin::speed = 110;
			}

			// Tick all enemies and objects, and remove nullptrs from deletions
			for (size_t i = 0; i < enemies.size(); i++) {
				if (enemies[i] == nullptr) continue;
				enemies[i]->update(dt);
			}
			enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
			for (size_t i = 0; i < objects.size(); i++) {
				if (objects[i] == nullptr) continue;
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

			break;
	}
	EndDrawing();
}

void Game::addEnemy(Enemy* obj) {
	enemies.push_back(obj);
}

// Find and delete a certain object from vectors and set to nullptr
void Game::removeEnemy(Enemy* obj) {
	auto it = std::find(enemies.begin(), enemies.end(), obj);
	if (it != enemies.end()) {
		*it = nullptr;
	}
	delete obj;
}

void Game::removeObject(GameObject* obj) {
	auto it = std::find(objects.begin(), objects.end(), obj);
	if (it != objects.end()) {
		*it = nullptr;
	}
	delete obj;
}

// When game restarts, we want to reset enemy stats and delete all enemies
void Game::resetEnemy() {
	time = 0;
	Goblin::spawnCooldown = 3.0f;
	Goblin::speed = 50;
	for (auto enemy : enemies) {
		delete enemy;
	}
	enemies.clear();
}

void Game::resetObjects() {
	for (auto obj : objects) {
		delete obj;
	}
	objects.clear();
}

// Save and load highscore by simply writing and reading a float from a text file
void Game::saveHighScore() {
	std::ofstream f;
	f.open("../highscore.txt");
	f << highScore;
	f.close();
}

void Game::loadHighScore() {
	std::ifstream f("../highscore.txt");
	// If this fails, highscore is just set to 0;
	f >> highScore;
	f.close();
}