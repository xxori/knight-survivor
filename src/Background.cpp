#include "Background.hpp"
#include "Game.hpp"

Background::Background(Game* game, int size) : GameObject(game, raylib::Vector2(0, 0)), size(size) {}

void Background::update(float dt) {}
void Background::draw() {
	// Grab player position using Game reference
	raylib::Vector2 playerPos = this->getGame()->getPlayer()->getPos();

	// Camera is rendered relative to player, with a half screen size offset
	// We want to move the tiles as the player moves too, so we add a mod size offset
	int startX = -playerPos.x + static_cast<int>(playerPos.x) % size + SCREEN_WIDTH / 2.0;
	int startY = -playerPos.y + static_cast<int>(playerPos.y) % size + SCREEN_HEIGHT / 2.0;

	// Loop from one square left of the screen to one square right of the screen
	for (int x = -size; x <= SCREEN_WIDTH + size; x += size) {
		for (int y = -size; y <= SCREEN_HEIGHT + size; y += size) {
			// Apply offeet to the player screen location
			int newX = x - startX;
			int newY = y - startY;

			// Create the checkerboard colors using mod 2 of the tile location
			raylib::Color color = ((x - static_cast<int>(playerPos.x / size)) + (y - static_cast<int>(playerPos.y / size))) % 2 == 0 ? GRAY : WHITE;
			DrawRectangle(newX, newY, size, size, color);
		}
	}
}
// We can hijack this code to maybe show random tiles or something, but itd probably
// be easier to make one massive tile texture and tile it over and over