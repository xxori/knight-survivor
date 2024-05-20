#include "ProjectileTest.hpp"
#include <iostream>

class TestingProjectile : public Projectile {
public:
	TestingProjectile(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* tex, int damage, float speed) : Projectile(game, pos, collider, tex, damage, speed) {}
	void draw() override {}
};

ProjectileTest::ProjectileTest(Game* game) {
	projectile = new TestingProjectile(game, raylib::Vector2 { 0, 0 }, raylib::Rectangle { 0, 0, 6, 6 }, nullptr, 6, 666);
}

ProjectileTest::~ProjectileTest() {
	delete projectile;
	projectile = nullptr;
}

void ProjectileTest::testDamage() {
	std::cout << "Testing: ProjectileTest::testDamage\n";
	bool pass { projectile->getDamage() == 6 };
	if (pass) {
		std::cout << "✅ Pass: ProjectileTest::testDamage\n";
	} else {
		std::cout << "❌ Fail: ProjectileTest::testDamage\n";
	}
}

void ProjectileTest::testSpeed() {
	std::cout << "Testing: ProjectileTest::testSpeed\n";
	bool pass { projectile->getSpeed() == 666 };
	if (pass) {
		std::cout << "✅ Pass: ProjectileTest::testSpeed\n";
	} else {
		std::cout << "❌ Fail: ProjectileTest::testSpeed\n";
	}
}

void ProjectileTest::runAllTests() {
	std::cout << "\n======== ProjectileTest ========\n";
	testDamage();
	testSpeed();
}