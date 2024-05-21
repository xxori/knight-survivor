#pragma once

#include "Player.hpp"
#include "common/GameObject.hpp"
#include "enemy/Enemy.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <vector>

const int SCREEN_HEIGHT = 450;
const int SCREEN_WIDTH = 800;

// All possible states the game can be in at any one time
enum GameState { Playing,
								 MainMenu,
								 Paused,
								 Dead,
								 Tutorial,
								 Confirmation
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

	// All HUD elements that are rendered using absolute coordinates on the screen
	std::vector<GameObject*> playingUI;

	// The different game menus are stored as a collection of gameobjects
	std::vector<GameObject*> mainMenu;
	std::vector<GameObject*> pauseMenu;
	std::vector<GameObject*> deadMenu;
	std::vector<GameObject*> tutorialMenu;
	std::vector<GameObject*> confirmationMenu;

	GameState state;

	raylib::Font font;

	// So that the pause menu doesn't flash every frame,
	// we need to detect when escape goes from unpressed to pressed.
	bool escapePressedLastFrame;

	// For the sake of score and increasing difficulty, we store
	// gametime and high score time.
	float time;
	float highScore;

public:
	Game();
	~Game();

	void updateAll();
	// Draw all objects relative to a camera
	void drawAll(raylib::Camera2D camera);

	// Return references to all enemies
	std::vector<Enemy*> getEnemies();

	// Add and remove objects from game
	void addEnemy(Enemy* entity);
	void removeEnemy(Enemy* entity);
	void addObject(GameObject* obj);
	void removeObject(GameObject* obj);

	void setState(GameState state);

	// Reset enemies and objects on game reset
	void resetEnemy();
	void resetObjects();

	float getTime();
	float getHighScore();

	raylib::Font* getFont();

	// Load and save highscore to a file
	void saveHighScore();
	void loadHighScore();

	// Get a reference to the player object
	Player* getPlayer();
};
