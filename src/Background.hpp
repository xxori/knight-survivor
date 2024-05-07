#pragma once

#include "GameObject.hpp"

// Background texture class
// For now, it prints a moving infinite checkerboard
// TODO: We should make it an image later
class Background : public GameObject {
private:
	// Size of each square in checkerboard
	int size;

public:
	Background(Game* game, int size);
	void draw() override;
	void update(float dt) override;
};