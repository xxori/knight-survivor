#include "EnemyTest.hpp"
#include <iostream>

class TestingEnemy : public Enemy {
public:
	TestingEnemy(Game* game, raylib::Rectangle collider, int health, int damage, float damageCooldown, float speed) : Enemy(game, collider, health, damage, damageCooldown, speed) {}
	void update(float dt) override {}
	void draw() override {}
};

EnemyTest::EnemyTest(Game* game) {
	enemy = new TestingEnemy(game, raylib::Rectangle(0, 0, 6, 6), 6, 6, 0, 6);
	enemyWithCooldown = new TestingEnemy(game, raylib::Rectangle(0, 0, 6, 6), 6, 6, 6, 6);
}

EnemyTest::~EnemyTest() {
	delete enemy;
	delete enemyWithCooldown;
}

void EnemyTest::testHealth() {
	std::cout << "Testing: EnemyTest::testHealth\n";
	enemy->getHealth();
	bool pass { enemy->getHealth() == 6 };
	if (pass) {
		std::cout << "✅ Pass: EnemyTest::testHealth\n";
	} else {
		std::cout << "❌ Fail: EnemyTest::testHealth\n";
	}
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
}

void EnemyTest::testSpawnPosition() {
	std::cout << "Testing: EnemyTest::testSpawnPosition\n";
	raylib::Vector2 spawnPos = enemy->getPos();
	bool pass { spawnPos.GetX() >= -SCREEN_WIDTH / 2.0 && spawnPos.GetX() <= SCREEN_WIDTH / 2.0 && spawnPos.GetY() >= -SCREEN_WIDTH / 2.0 && spawnPos.GetY() <= SCREEN_WIDTH / 2.0 };
	if (pass) {
		std::cout << "✅ Pass: EnemyTest::testSpawnPosition\n";
	} else {
		std::cout << "❌ Fail: EnemyTest::testSpawnPosition\n";
	}
}

void EnemyTest::testDamage() {
	std::cout << "Testing: EnemyTest::testDamage\n";
	bool pass { enemy->getDamage() == 6 };
	if (pass) {
		std::cout << "✅ Pass: EnemyTest::testDamage\n";
	} else {
		std::cout << "❌ Fail: EnemyTest::testDamage\n";
	}
}

void EnemyTest::runAllTests() {
	std::cout << "\n======== EnemyTest ========\n";
	testHealth();
	testTakeDamage();
	testTakeDamageWhenCooldown();
	testSpawnPosition();
	testDamage();
}