#pragma once

#include "GameEntity.hpp"
#include "Player.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <vector>

// Overall game state object, holding all other objects
class Game {
private:
	// The player to be rendered at center of screen
	Player* player;

	// All game entities that are rendered relative to player using relative map coordinates
	std::vector<GameEntity*> entities;

	// All UI elements that are rendered using absolute coordinates on the screen
	// TODO: Maybe make this a different class than GameEntity?
	std::vector<GameEntity*> uiEntities;

	// Time since last frame. Can be used to calculate FPS
	// Also used in physics calculations to make game run same regardless of FPS
	float dt;

public:
	Game();
	~Game();

	void updateAll();
	void drawAll(raylib::Camera2D camera);
	void addEntity(GameEntity* entity);
	void addUIEntity(GameEntity* entity);

	// Get a reference to the player object
	Player* getPlayer();
};
