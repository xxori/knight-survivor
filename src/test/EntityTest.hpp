#pragma once
#include "../Game.hpp"
#include "../common/GameEntity.hpp"

class EntityTest {
private:
	GameEntity* entity1;
	GameEntity* entity2;
	void testCenter();
	void testCollide();
	void testCollider();
	void testPosition();

public:
	EntityTest(Game* game);
	~EntityTest();
	void runAllTests();
};