#include "ButtonTest.hpp"
#include "Color.hpp"
#include <iostream>

ButtonTest::ButtonTest(Game* game) {
	button = new Button(game, nullptr, raylib::Vector2 { 0, 0 }, RAYWHITE, RAYWHITE, "Test Button", 6, 6, RAYWHITE);
}

ButtonTest::~ButtonTest() {
	delete button;
	button = nullptr;
}

void ButtonTest::testColor() {
	std::cout << "Testing: ButtonTest::testColor\n";
	raylib::Color color = button->getColor();
	bool pass { color.r == 245 && color.g == 245 && color.b == 245 && color.a == 255 };
	if (pass) {
		std::cout << "✅ Pass: ButtonTest::testColor\n";
	} else {
		std::cout << "❌ Fail: ButtonTest::testColor\n";
	}
}

void ButtonTest::testText() {
	std::cout << "Testing: ButtonTest::testText\n";
	bool pass { button->getText() == "Test Button" };
	if (pass) {
		std::cout << "✅ Pass: ButtonTest::testText\n";
	} else {
		std::cout << "❌ Fail: ButtonTest::testText\n";
	}
}

void ButtonTest::testMargin() {
	std::cout << "Testing: ButtonTest::testMargin\n";
	bool pass { button->getMargin() == 6 };
	if (pass) {
		std::cout << "✅ Pass: ButtonTest::testMargin\n";
	} else {
		std::cout << "❌ Fail: ButtonTest::testMargin\n";
	}
}

void ButtonTest::testFontSize() {
	std::cout << "Testing: ButtonTest::testFontSize\n";
	bool pass { button->getFontSize() == 6 };
	if (pass) {
		std::cout << "✅ Pass: ButtonTest::testFontSize\n";
	} else {
		std::cout << "❌ Fail: ButtonTest::testFontSize\n";
	}
}

void ButtonTest::testFontColor() {
	std::cout << "Testing: ButtonTest::testFontColor\n";
	raylib::Color color = button->getFontColor();
	bool pass { color.r == 245 && color.g == 245 && color.b == 245 && color.a == 255 };
	if (pass) {
		std::cout << "✅ Pass: ButtonTest::testFontColor\n";
	} else {
		std::cout << "❌ Fail: ButtonTest::testFontColor\n";
	}
}

void ButtonTest::runAllTests() {
	std::cout << "\n======== ButtonTest ========\n";
	testColor();
	testText();
	testMargin();
	testFontSize();
	testFontColor();
}