#include "EntityTest.hpp"
#include <iostream>

class TestingEntity : public GameEntity {
public:
	TestingEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture) : GameEntity(game, pos, collider, texture) {}
	void update(float dt) override {}
	void draw() override {}
};

EntityTest::EntityTest() {
	entity1 = new TestingEntity(nullptr, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 10, 10), nullptr);
	entity2 = new TestingEntity(nullptr, raylib::Vector2(0, 0), raylib::Rectangle(6, 6, 10, 10), nullptr);
}

void EntityTest::testCenter() {
	std::cout << "Testing: EntityTest::testCenter\n";
	raylib::Vector2 center { entity1->getCenter() };
	bool pass { center.GetX() == 5 && center.GetY() == 5 };
	if (pass) {
		std::cout << "✅ Pass: EntityTest::testCenter\n";
	} else {
		std::cout << "❌ Fail: EntityTest::testCenter\n";
	}
	std::cout << "\n";
}

void EntityTest::testCollide() {
	std::cout << "Testing: EntityTest::testCollide\n";
	bool pass { entity1->collide(entity2) };
	if (pass) {
		std::cout << "✅ Pass: EntityTest::testCollide\n";
	} else {
		std::cout << "❌ Fail: EntityTest::testCollide\n";
	}
	std::cout << "\n";
}

void EntityTest::runAllTests() {
	testCenter();
	testCollide();
}