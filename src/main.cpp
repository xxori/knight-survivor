#include "raylib-cpp.hpp" // IWYU pragma: keep
#include "Game.hpp"
#include "FPSCounter.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT);
	raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "GAME");
	// SetTargetFPS(60);
	
	Game game = Game();
	game.AddEntity(new FPSCounter());
	while (!window.ShouldClose()) {
		game.UpdateAll();
		BeginDrawing();
		game.DrawAll();	
		EndDrawing();
	}

	return 0;
}
