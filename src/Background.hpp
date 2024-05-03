#pragma once

#include "GameEntity.hpp"

// Background texture class
// For now, it prints a moving infinite checkerboard
// TODO: We should make it an image later
class Background : public GameEntity {
private:
	// Size of each square in checkerboard
	int size;

public:
	Background(Game* game, int size);
	void Draw();
};