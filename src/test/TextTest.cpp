#include "TextTest.hpp"
#include <iostream>

TextTest::TextTest(Game* game) {
	text = new Text(game, "Test Text", raylib::Vector2 { 6, 6 }, 6, RAYWHITE);
}

TextTest::~TextTest() {
	delete text;
}

void TextTest::testSize() {
	std::cout << "Testing: TextTest::testSize\n";
	bool pass { text->getSize() == 6 };
	if (pass) {
		std::cout << "✅ Pass: TextTest::testSize\n";
	} else {
		std::cout << "❌ Fail: TextTest::testSize\n";
	}
}

void TextTest::testText() {
	std::cout << "Testing: TextTest::testText\n";
	bool pass { text->getText() == "Test Text" };
	if (pass) {
		std::cout << "✅ Pass: TextTest::testText\n";
	} else {
		std::cout << "❌ Fail: TextTest::testText\n";
	}
}

void TextTest::runAllTests() {
	std::cout << "\n======== TextTest ========\n";
	testSize();
	testText();
}