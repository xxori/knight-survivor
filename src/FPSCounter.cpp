#include "FPSCounter.hpp"
#include <string>

// Average fps over 60 frames
int FPSCounter::max_count = 60;

// Initialise the Text parent class, and dt_average and count as 0
FPSCounter::FPSCounter(Game* game) : Text(game, "fps: ", raylib::Vector2(10, 10), 20, GREEN), dt_average(0), counter(0) {}

void FPSCounter::Update(float dt) {
	// Add to the average
	dt_average += dt / max_count;
	if (++counter > max_count) {
		// Once counter reaches max count, reset counter and update text
		counter = 0;
		this->set_text("fps: " + std::to_string((int)(1 / dt_average)));
		dt_average = 0;
	}
}