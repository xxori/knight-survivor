#pragma once

#include "GameEntity.hpp"

// A simple text class that represents some text rendered to the screen
class Text : public GameEntity {
private:
	std::string text;
	int size;
	raylib::Color color;

public:
	Text(Game* game);
	Text(Game* game, std::string text, raylib::Vector2 pos, int size, raylib::Color color);

	void update(float dt);
	void draw();

	int getSize();
	void setSize(int size);
	std::string getText();
	void setText(std::string text);
};
