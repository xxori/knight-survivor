#include "Background.hpp"
#include "Game.hpp"

Background::Background(Game* game, int size) : GameEntity(game), size(size) {}

void Background::Draw() {
	// Grab player position using Game reference
	raylib::Vector2 playerPos = this->get_game()->get_player()->get_pos();

	// Camera is rendered relative to player, with a half screen size offset
	// We want to move the tiles as the player moves too, so we add a mod size offset
	int startX = -playerPos.x + (int)playerPos.x % size + 800 / 2.0;
	int startY = -playerPos.y + (int)playerPos.y % size + 450 / 2.0;

	// Loop from one square left of the screen to one square right of the screen
	for (int x = -size; x < 800 + size; x += size) {
		for (int y = -size; y < 450 + size; y += size) {
			// Apply offeet to the player screen location
			int newX = x - startX;
			int newY = y - startY;

		// Create the checkerboard colors using mod 2 of the tile location
		raylib:
			Color color = ((x - (int)(playerPos.x / size)) + (y - (int)(playerPos.y / size))) % 2 == 0 ? GRAY : WHITE;
			DrawRectangle(newX, newY, size, size, color);
		}
	}
}
// We can hijack this code to maybe show random tiles or something, but itd probably
// be easier to make one massive tile texture and tile it over and over