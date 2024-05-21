#include "WeaponTest.hpp"
#include <iostream>

class TestingWeapon : public Weapon {
public:
	TestingWeapon(Game* game, int fireSpeed) : Weapon(game, fireSpeed) {}
	void update(float dt) override {}
};

WeaponTest::WeaponTest(Game* game) {
	weapon = new TestingWeapon(game, 6);
}

WeaponTest::~WeaponTest() {
	delete weapon;
}

void WeaponTest::testFireSpeed() {
	std::cout << "Testing: WeaponTest::testFireSpeed\n";
	float fireSpeed { weapon->getFireSpeed() };
	bool pass { fireSpeed == 6 };
	if (pass) {
		std::cout << "✅ Pass: WeaponTest::testFireSpeed\n";
	} else {
		std::cout << "❌ Fail: WeaponTest::testFireSpeed\n";
	}
}

void WeaponTest::testTimeToFire() {
	std::cout << "Testing: WeaponTest::testTimeToFire\n";
	float timeToFire { weapon->getTimeToFire() };
	bool pass { timeToFire == 6 };
	if (pass) {
		std::cout << "✅ Pass: WeaponTest::testTimeToFire\n";
	} else {
		std::cout << "❌ Fail: WeaponTest::testTimeToFire\n";
	}
}

void WeaponTest::runAllTests() {
	std::cout << "\n======== WeaponTest ========\n";
	testFireSpeed();
	testTimeToFire();
}