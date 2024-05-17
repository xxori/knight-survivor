#include "FPSCounter.hpp"
#include <string>

// Average fps over 60 frames
int FPSCounter::maxCount = 60;

// Initialise the Text parent class, and dt_average and count as 0
FPSCounter::FPSCounter(Game* game) : Text(game, "fps: ", raylib::Vector2(10, 10), 20, GREEN), dtAverage(0), counter(0) {}

void FPSCounter::update(float dt) {
	// Add to the average
	dtAverage += dt / maxCount;
	if (++counter > maxCount) {
		// Once counter reaches max count, reset counter and update text
		counter = 0;
		this->setText("fps: " + std::to_string(static_cast<int>(1 / dtAverage)));
		dtAverage = 0;
	}
}