#include "ButtonTest.hpp"
#include "EnemyTest.hpp"
#include "EntityTest.hpp"
#include "ProjectileTest.hpp"
#include "TextTest.hpp"
#include "WeaponTest.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <raylib.h>

int main() {
	Game game;
	EntityTest entityTest(&game);
	entityTest.runAllTests();
	EnemyTest enemyTest(&game);
	enemyTest.runAllTests();
	WeaponTest weaponTest(&game);
	weaponTest.runAllTests();
	ProjectileTest projectileTest(&game);
	projectileTest.runAllTests();
	TextTest textTest(&game);
	textTest.runAllTests();
	ButtonTest buttonTest(&game);
	buttonTest.runAllTests();
	return 0;
}