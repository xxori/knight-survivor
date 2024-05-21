#include "PlayerTest.hpp"
#include <iostream>

PlayerTest::PlayerTest(Game* game) {
	player = new Player(game);
}

PlayerTest::~PlayerTest() {
	delete player;
}

void PlayerTest::testTakeDamage() {
	std::cout << "Testing: PlayerTest::testTakeDamage\n";
	player->update(6);
	player->takeDamage(2);
	bool pass { player->getHealth() == 3 };
	if (pass) {
		std::cout << "✅ Pass: PlayerTest::testTakeDamage\n";
	} else {
		std::cout << "❌ Fail: PlayerTest::testTakeDamage\n";
	}
}

void PlayerTest::testResetStats() {
	std::cout << "Testing: PlayerTest::testResetStats\n";
	player->resetStats();
	bool pass { player->getHealth() == 5 && player->getLevel() == 1 && player->getXp() == 0 && player->getSpeed() == 125.0 };
	if (pass) {
		std::cout << "✅ Pass: PlayerTest::testResetStats\n";
	} else {
		std::cout << "❌ Fail: PlayerTest::testResetStats\n";
	}
}

void PlayerTest::testDirection() {
	std::cout << "Testing: PlayerTest::testDirection\n";
	player->setDirection(raylib::Vector2(1, 1));
	bool pass { player->getDirection() == raylib::Vector2(1, 1) };
	if (pass) {
		std::cout << "✅ Pass: PlayerTest::testDirection\n";
	} else {
		std::cout << "❌ Fail: PlayerTest::testDirection\n";
	}
}

void PlayerTest::runAllTests() {
	std::cout << "\n======== PlayerTest ========\n";
	testTakeDamage();
	testResetStats();
	testDirection();
}