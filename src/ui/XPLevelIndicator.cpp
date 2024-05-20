#include "XPLevelIndicator.hpp"
#include "../Game.hpp"
#include "Functions.hpp"
#include <format>

XPLevelIndicator::XPLevelIndicator(Game* game) : Text(game, "XP: \nLevel:", raylib::Vector2(0, 0), 36, BLUE) {}

void XPLevelIndicator::update(float dt) {
	Player* player = getGame()->getPlayer();
	setText(std::format("XP: {}/{}\n\nLevel: {}", player->getXp(), player->getLevel() * 5, player->getLevel()));
	auto width = raylib::MeasureText(getText(), 36);
	setPos(raylib::Vector2(SCREEN_WIDTH - width - 10, SCREEN_HEIGHT - 72 - 10));
}
