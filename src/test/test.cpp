#include "EnemyTest.hpp"
#include "EntityTest.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <raylib.h>

int main() {
	Game game;
	EntityTest entityTest(&game);
	entityTest.runAllTests();
	EnemyTest enemyTest(&game);
	enemyTest.runAllTests();
	return 0;
}