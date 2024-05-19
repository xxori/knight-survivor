#pragma once
#include "../Game.hpp"
#include "../common/GameEntity.hpp"

class EntityTest {
private:
	Game* game;
	GameEntity* entity1;
	GameEntity* entity2;
	void testCenter();
	void testCollide();

public:
	EntityTest();
	void runAllTests();
};