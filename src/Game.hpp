#pragma once

#include "Player.hpp"
#include "common/GameObject.hpp"
#include "enemy/Enemy.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <vector>

const int SCREEN_HEIGHT = 450;
const int SCREEN_WIDTH = 800;

enum GameState { Playing,
	MainMenu,
	Paused,
	Dead,
	Tutorial
};

// Overall game state object, holding all other objects
class Game {
private:
	// The player to be rendered at center of screen
	Player* player;

	// All game entities that are rendered relative to player using relative map coordinates
	std::vector<Enemy*> enemies;
	std::vector<GameObject*> objects; // Other objects including projectiles
	GameObject* background;

	// All UI elements that are rendered using absolute coordinates on the screen
	std::vector<GameObject*> playingUI;

	std::vector<GameObject*> mainMenu;
	std::vector<GameObject*> pauseMenu;
	std::vector<GameObject*> deadMenu;
	std::vector<GameObject*> tutorialMenu;

	GameState state;

public:
	Game();
	~Game();

	void updateAll();
	void drawAll(raylib::Camera2D camera);
	void addEnemy(Enemy* entity);
	void removeEnemy(Enemy* entity);
	void addObject(GameObject* obj);
	void removeObject(GameObject* obj);
	void addUIObject(GameObject* entity);
	void setState(GameState state);
	std::vector<Enemy*> getEnemies();
	void resetEnemy();
	void resetObjects();

	// Get a reference to the player object
	Player* getPlayer();
};
