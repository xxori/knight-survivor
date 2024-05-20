#include "WeaponTest.hpp"
#include <iostream>

class TestingWeapon : public Weapon {
public:
	TestingWeapon(Game* game, std::string name, int fireSpeed) : Weapon(game, name, fireSpeed) {}
	void update(float dt) override {}
};

WeaponTest::WeaponTest(Game* game) {
	weapon = new TestingWeapon(game, "Test Weapon", 6);
}

WeaponTest::~WeaponTest() {
	delete weapon;
	weapon = nullptr;
}

void WeaponTest::testName() {
	std::cout << "Testing: WeaponTest::testName\n";
	std::string name { weapon->getName() };
	bool pass { name == "Test Weapon" };
	if (pass) {
		std::cout << "✅ Pass: WeaponTest::testName\n";
	} else {
		std::cout << "❌ Fail: WeaponTest::testName\n";
	}
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
	testName();
	testFireSpeed();
	testTimeToFire();
}