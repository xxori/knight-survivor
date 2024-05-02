#include "FPSCounter.hpp"
#include <format>

int FPSCounter::max_count = 60;

FPSCounter::FPSCounter():  Text("fps: ", raylib::Vector2(10,10), 20, GREEN), dt_average(0), counter(0){}

void FPSCounter::Update(float dt) {
    dt_average += dt / max_count;
    if (++counter > max_count) {
        counter = 0;
        text = std::format("fps: {:.2f}", 1/dt_average);
        dt_average = 0;
    }
}