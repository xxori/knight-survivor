#include "EntityTest.hpp"
#include <iostream>

class TestingEntity : public GameEntity {
public:
	TestingEntity(Game* game, raylib::Vector2 pos, raylib::Rectangle collider, raylib::Texture* texture) : GameEntity(game, pos, collider, texture) {}
	void update(float dt) override {}
	void draw() override {}
};

EntityTest::EntityTest(Game* game) {
	entity1 = new TestingEntity(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 10, 10), nullptr);
	entity2 = new TestingEntity(game, raylib::Vector2(6, 6), raylib::Rectangle(0, 0, 10, 10), nullptr);
}

EntityTest::~EntityTest() {
	delete entity1;
	entity1 = nullptr;
	delete entity2;
	entity2 = nullptr;
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

void EntityTest::testCollider() {
	std::cout << "Testing: EntityTest::testCollider\n";
	raylib::Rectangle collider { entity1->getCollider() };
	bool pass { collider.GetX() == 0 && collider.GetY() == 0 && collider.GetWidth() == 10 && collider.GetHeight() == 10 };
	if (pass) {
		std::cout << "✅ Pass: EntityTest::testCollider\n";
	} else {
		std::cout << "❌ Fail: EntityTest::testCollider\n";
	}
	std::cout << "\n";
}

void EntityTest::testPosition() {
	std::cout << "Testing: EntityTest::testPosition\n";
	raylib::Vector2 pos { entity1->getPos() };
	bool pass { pos.GetX() == 0 && pos.GetY() == 0 };
	if (pass) {
		std::cout << "✅ Pass: EntityTest::testPosition\n";
	} else {
		std::cout << "❌ Fail: EntityTest::testPosition\n";
	}
	std::cout << "\n";
}

void EntityTest::runAllTests() {
	testCenter();
	testCollide();
	testCollider();
	testPosition();
}