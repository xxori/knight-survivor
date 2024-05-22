#include "Game.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <raylib.h>

int main() {

	// Use vsync instead of a capped FPS
	SetConfigFlags(FLAG_VSYNC_HINT);
	raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Knight Survivors");

	// Construct game and load highscore from file
	Game game = Game();
	game.loadHighScore();

	// Create a 2D camera centered on the player
	// This allows us to use rotation and zoom in the future
	raylib::Camera2D camera = raylib::Camera2D();
	SetExitKey(KEY_Q);
	camera.target = game.getPlayer()->getPos();
	camera.offset = raylib::Vector2(SCREEN_WIDTH / 2.0 - game.getPlayer()->getCollider().GetWidth() / 2.0, SCREEN_HEIGHT / 2.0 - game.getPlayer()->getCollider().GetHeight() / 2.0);
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Simple game loop, closes when press Q or x button
	while (!window.ShouldClose()) {
		game.updateAll();

		// We want our camera centered on the player
		camera.target = game.getPlayer()->getPos();
		game.drawAll(camera);
	}

	// Save our highscore to a file
	game.saveHighScore();
	return 0;
}
