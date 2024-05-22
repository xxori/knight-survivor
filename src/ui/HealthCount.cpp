#include "HealthCount.hpp"
#include "../Game.hpp"
#include <format>

HealthCount::HealthCount(Game* game) : Text(game, "Health: ", raylib::Vector2(10, SCREEN_HEIGHT - 36 - 10), 36, RED) {}

void HealthCount::update(float dt) {
	setText(std::format("Health: {}", getGame()->getPlayer()->getHealth()));
}