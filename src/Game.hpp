#ifndef GAME_HPP
#define GAME_HPP
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
	std::vector<GameEntity*> ui_entities;

	// Time since last frame. Can be used to calculate FPS
	// Also used in physics calculations to make game run same regardless of FPS
	float dt;

public:
	Game();
	~Game();

	void UpdateAll();
	void DrawAll(raylib::Camera2D camera);
	void AddEntity(GameEntity* entity);
	void AddUIEntity(GameEntity* entity);

	// Get a reference to the player object
	Player* get_player();
};

#endif