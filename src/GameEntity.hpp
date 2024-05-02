#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP
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
	virtual void Update(float dt);
	virtual void Draw();
	raylib::Vector2 get_pos();
	void set_pos(raylib::Vector2 pos);
    Game *get_game();
};

#endif