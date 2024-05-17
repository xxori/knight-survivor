#pragma once

#include "../common/GameObject.hpp"

class Button : public GameObject {
private:
	std::string text;
	int margin;
	int fontSize;
	raylib::Color fontColor;
	raylib::Color color; // current color;
	const raylib::Color hoverColor;
	const raylib::Color normalColor;
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