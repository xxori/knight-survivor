#include "PlayerTest.hpp"
#include <iostream>

PlayerTest::PlayerTest(Game* game) {
	player = new Player(game);
}

PlayerTest::~PlayerTest() {
	delete player;
	player = nullptr;
}

void PlayerTest::testTakeDamage() {
	std::cout << "Testing: PlayerTest::testTakeDamage\n";
	player->update(6);
	player->takeDamage(2);
	bool pass { player->getHealth() == 8 };
	if (pass) {
		std::cout << "✅ Pass: PlayerTest::testTakeDamage\n";
	} else {
		std::cout << "❌ Fail: PlayerTest::testTakeDamage\n";
	}
}

void PlayerTest::testResetHealth() {
	std::cout << "Testing: PlayerTest::testResetHealth\n";
	player->resetHealth();
	bool pass { player->getHealth() == 10 };
	if (pass) {
		std::cout << "✅ Pass: PlayerTest::testResetHealth\n";
	} else {
		std::cout << "❌ Fail: PlayerTest::testResetHealth\n";
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
	testResetHealth();
	testDirection();
}