#pragma once

#include "GameObject.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <vector>

const int SCREEN_HEIGHT = 450;
const int SCREEN_WIDTH = 800;

// Overall game state object, holding all other objects
class Game {
private:
	// The player to be rendered at center of screen
	Player* player;

	// All game entities that are rendered relative to player using relative map coordinates
	std::vector<GameObject*> enemies;
	std::vector<Projectile*> projectiles;

	// All UI elements that are rendered using absolute coordinates on the screen
	// TODO: Maybe make this a different class than GameEntity?
	std::vector<GameObject*> uiObjects;

public:
	Game();
	~Game();

	void updateAll();
	void drawAll(raylib::Camera2D camera);
	void addEnemy(GameObject* entity);
	void removeEnemy(GameObject* entity);
	void addProjectile(Projectile* entity);
	void removeProjectile(Projectile* entity);
	void addUIObject(GameObject* entity);

	// Get a reference to the player object
	Player* getPlayer();
};
