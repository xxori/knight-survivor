#pragma once

#include "../common/GameObject.hpp"

// A button that displays text and performs an action on click
class Button : public GameObject {
private:
	std::string text;

	// Space between text and color border
	int margin;

	int fontSize;

	raylib::Color fontColor;

	// Font color when mouse is hovering
	const raylib::Color hoverColor;
	// The default non-hover font color
	const raylib::Color normalColor;

	// The current button color
	raylib::Color color;

	// A function pointer for the callback when ubtton is clicked,
	// performing an operation using the game pointer
	void (*callback)(Game*);

public:
	Button(Game* game);
	Button(Game* game, void (*callback)(Game* game), raylib::Vector2 pos, raylib::Color color, raylib::Color hoverColor, std::string text, int margin, int fontSize, raylib::Color fontColor);

	void update(float dt) override;
	void draw() override;

	raylib::Color getColor();
	void setColor(raylib::Color color);
	void setText(std::string text);
	std::string getText();
	void setMargin(int margin);
	int getMargin();
	void setFontSize(int fontSize);
	int getFontSize();
	void setFontColor(raylib::Color color);
	raylib::Color getFontColor();
};