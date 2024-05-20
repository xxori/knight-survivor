#pragma once

#include "../Game.hpp"
#include "../ui/Text.hpp"

class TextTest {
private:
	Text* text;
	void testSize();
	void testText();

public:
	TextTest(Game* game);
	~TextTest();
	void runAllTests();
};