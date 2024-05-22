#pragma once

#include "common/GameObject.hpp"

// Background texture class
// It draws a checkerboard pattern that moves as the player moves,
// giving the illusion of an infinite plane.
class Background : public GameObject {
private:
	// Size of each square in checkerboard
	int size;

public:
	Background(Game* game, int size);
	void draw() override;
	void update(float dt) override;
};