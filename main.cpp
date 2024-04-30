#include "raylib-cpp.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

int main() {
	raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "GAME");
	SetTargetFPS(60);

	while (!window.ShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Congrats! You created your first raylib-cpp window!", 160, 200, 20,
						 LIGHTGRAY);
		EndDrawing();
	}

	return 0;
}
