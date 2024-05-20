#pragma once
#include "../Game.hpp"
#include "../ui/Button.hpp"

class ButtonTest {
private:
	Button* button;
	void testColor();
	void testText();
	void testMargin();
	void testFontSize();
	void testFontColor();

public:
	ButtonTest(Game* game);
	~ButtonTest();
	void runAllTests();
};