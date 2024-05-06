#pragma once

#include "raylib-cpp.hpp" // IWYU pragma: keep

// Forward declaration of Game class
// Our GameEntity stores a pointer to it but we dont want circular includes
class Game;

// Class representing every entity that exists in our game
class GameEntity {
private:
	// Store a position and a reference to the global game object
	raylib::Vector2 pos;
	Game* game;

public:
	GameEntity(Game* game);
	virtual void update(float dt);
	virtual void draw();
	raylib::Vector2 getPos();
	void setPos(raylib::Vector2 pos);
	Game* getGame();
};
