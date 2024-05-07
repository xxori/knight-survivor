#pragma once

#include "raylib-cpp.hpp" // IWYU pragma: keep

// Forward declaration of Game class
// Our GameEntity stores a pointer to it but we dont want circular includes
class Game;

// Class representing every entity that exists in our game
class GameObject {
private:
	// Store a position and a reference to the global game object
	raylib::Vector2 pos;
	Game* game;

public:
	GameObject(Game* game, raylib::Vector2 pos);
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	virtual ~GameObject();
	raylib::Vector2 getPos();
	void setPos(raylib::Vector2 pos);
	Game* getGame();
};
