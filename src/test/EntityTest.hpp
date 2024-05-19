#pragma once
#include "../common/GameEntity.hpp"

class EntityTest {
private:
	GameEntity* entity1;
	GameEntity* entity2;
	void testCenter();
	void testCollide();

public:
	EntityTest();
	void runAllTests();
};