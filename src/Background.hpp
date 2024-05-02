#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
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

#endif