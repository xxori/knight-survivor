#pragma once

#include "Text.hpp"

// A FPS Counter text for debugging use to measure game speed
class FPSCounter : public Text {
private:
	// We average FPS over some number of frames to make it more readable
	// Every max_count the FPS is updated with the average
	static int max_count;
	// State to count up to max_count
	int counter;
	// Measure the average dt over max_count frames
	float dt_average;

public:
	FPSCounter(Game* game);
	void Update(float dt) override;
};
