#pragma once

#include "../Game.hpp"
#include "../projectile/Projectile.hpp"

class ProjectileTest {
private:
	Projectile* projectile;
	void testDamage();
	void testSpeed();

public:
	ProjectileTest(Game* game);
	~ProjectileTest();
	void runAllTests();
};