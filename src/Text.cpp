#include "Text.hpp"

Text::Text() : Text("", raylib::Vector2(0,0), 20, GRAY) {}
Text::Text(std::string text, raylib::Vector2 pos, int size, raylib::Color color) : text(text), size(size), color(color) {
    this->pos = pos;
}

void Text::Draw() {
	raylib::DrawText(text, pos.x, pos.y, size, color);
}

void Text::Update(float dt) {}