#include "Game.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

int main() {

	// Use vsync instead of a capped FPS
	SetConfigFlags(FLAG_VSYNC_HINT);
	raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "GAME");

	// SetTargetFPS(60);

	Game game = Game();

	// Create a 2D camera centered on the player
	// This allows us to use rotation and zoom in the future
	raylib::Camera2D camera = raylib::Camera2D();
	camera.target = game.getPlayer()->getPos();
	camera.offset = raylib::Vector2(SCREEN_WIDTH / 2.0 - game.getPlayer()->getCollider().GetWidth() / 2.0, SCREEN_HEIGHT / 2.0 - game.getPlayer()->getCollider().GetHeight() / 2.0);
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Simple game loop, closes when press escape or x button
	while (!window.ShouldClose()) {
		game.updateAll();
		camera.target = game.getPlayer()->getPos();
		game.drawAll(camera);
	}

	return 0;
}
