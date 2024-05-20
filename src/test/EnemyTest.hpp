#pragma once
#include "../Game.hpp"
#include "../enemy/Enemy.hpp"

class EnemyTest {
private:
	Enemy* enemy;
	Enemy* enemyWithCooldown;
	void testTakeDamage();
	void testTakeDamageWhenCooldown();
	void testHealth();
	void testSpawnPosition();
	void testDamage();

public:
	EnemyTest(Game* game);
	~EnemyTest();
	void runAllTests();
};