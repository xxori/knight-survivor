#include "Text.hpp"
#include "../Game.hpp"

// Default contructor for empty string
Text::Text(Game* game) : Text(game, "", raylib::Vector2(0, 0), 20, WHITE) {}

Text::Text(Game* game, std::string text, raylib::Vector2 pos, int size, raylib::Color color) : GameObject(game, pos), text(text), size(size), color(color) {
	this->setPos(pos);
}

// Render text at the given position
void Text::draw() {
	// raylib::DrawText(text, this->getPos().x, this->getPos().y, size, color);
	getGame()->getFont()->DrawText(text, this->getPos(), size, 0, color);
}

// Standard getters and setters
int Text::getSize() { return size; }
void Text::setSize(int size) { this->size = size; }
std::string Text::getText() { return text; }
void Text::setText(std::string text) { this->text = text; }

// The base text class is static and doesn't change on updates
// Implementers can override this to allow changing text.
void Text::update(float dt) {}