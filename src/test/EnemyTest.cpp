#include "EnemyTest.hpp"
#include <iostream>

class TestingEnemy : public Enemy {
public:
	TestingEnemy(Game* game, raylib::Rectangle collider, raylib::Texture* texture, int health, int damage, float damageCooldown, float speed) : Enemy(game, collider, texture, health, damage, damageCooldown, speed) {}
	void update(float dt) override {}
	void draw() override {}
};

EnemyTest::EnemyTest(Game* game) {
	enemy = new TestingEnemy(game, raylib::Rectangle(0, 0, 6, 6), nullptr, 6, 6, 0, 6);
	enemyWithCooldown = new TestingEnemy(game, raylib::Rectangle(0, 0, 6, 6), nullptr, 6, 6, 6, 6);
}

EnemyTest::~EnemyTest() {
	delete enemy;
	enemy = nullptr;
	delete enemyWithCooldown;
	enemyWithCooldown = nullptr;
}

void EnemyTest::testTakeDamage() {
	std::cout << "Testing: EnemyTest::testTakeDamage\n";
	enemy->takeDamage(3);
	bool pass { enemy->getHealth() == 3 };
	if (pass) {
		std::cout << "✅ Pass: EnemyTest::testTakeDamage\n";
	} else {
		std::cout << "❌ Fail: EnemyTest::testTakeDamage\n";
	}
	std::cout << "\n";
}

void EnemyTest::testTakeDamageWhenCooldown() {
	std::cout << "Testing: EnemyTest::testTakeDamageWhenCooldown\n";
	enemyWithCooldown->takeDamage(3);
	bool pass { enemyWithCooldown->getHealth() == 6 };
	if (pass) {
		std::cout << "✅ Pass: EnemyTest::testTakeDamageWhenCooldown\n";
	} else {
		std::cout << "❌ Fail: EnemyTest::testTakeDamageWhenCooldown\n";
	}
	std::cout << "\n";
}

void EnemyTest::runAllTests() {
	testTakeDamage();
	testTakeDamageWhenCooldown();
}