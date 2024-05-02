#include "Text.hpp"

// Default contructor for empty string
Text::Text(Game* game) : Text(game, "", raylib::Vector2(0, 0), 20, WHITE) {}

Text::Text(Game* game, std::string text, raylib::Vector2 pos, int size, raylib::Color color) : GameEntity(game), text(text), size(size), color(color) {
	this->set_pos(pos);
}

// Render text at the given position
void Text::Draw() {
	raylib::DrawText(text, this->get_pos().x, this->get_pos().y, size, color);
}

// Standard getters and setters
int Text::get_size() { return size; }
void Text::set_size(int size) { this->size = size; }
std::string Text::get_text() { return text; }
void Text::set_text(std::string text) { this->text = text; }

// The base text class is static and doesn't change on updates
// Implementers can override this to allow changing text.
void Text::Update(float dt) {}