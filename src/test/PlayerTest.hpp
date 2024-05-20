#pragma once
#include "../Player.hpp"

class PlayerTest {
private:
	Player* player;
	void testTakeDamage();
	void testResetHealth();
	void testDirection();

public:
	PlayerTest(Game* game);
	~PlayerTest();
	void runAllTests();
};