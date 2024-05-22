#pragma once
#include "../Game.hpp"
#include "../weapon/Weapon.hpp"

class WeaponTest {
private:
	Weapon* weapon;
	void testFireSpeed();
	void testTimeToFire();

public:
	WeaponTest(Game* game);
	~WeaponTest();
	void runAllTests();
};