#include "Button.hpp"
#include "../Game.hpp"
#include <raylib.h>

Button::Button(Game* game) : Button(game, [](Game* game) {}, raylib::Vector2(0, 0), WHITE, WHITE, "", 0, 0, WHITE) {}

Button::Button(Game* game, void (*callback)(Game* game), raylib::Vector2 pos, raylib::Color color, raylib::Color hoverColor, std::string text, int margin, int fontSize, raylib::Color fontColor) : GameObject(game, pos), normalColor(color), color(color), text(text), margin(margin), fontSize(fontSize), fontColor(fontColor), callback(callback), hoverColor(hoverColor) {}

void Button::update(float dt) {
	raylib::Vector2 mousePos = GetMousePosition();
	int width = MeasureText(text.c_str(), fontSize);

	if (mousePos.x >= this->getPos().x && mousePos.y >= this->getPos().y && mousePos.x <= this->getPos().x + width + 2 * margin && mousePos.y <= this->getPos().y + fontSize + 2 * margin) { // if mouseclick inside button area
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			// If clicked
			callback(getGame());
		} else {
			// If hovered
			this->setColor(hoverColor);
		}
	} else {
		// Reset color
		this->setColor(normalColor);
	}
}

void Button::draw() {
	int width = MeasureText(text.c_str(), fontSize);
	DrawRectangle(this->getPos().x, this->getPos().y, width + 2 * margin, fontSize + 2 * margin, color);
	getGame()->getFont()->DrawText(text, this->getPos() + raylib::Vector2(margin, margin), fontSize, 0, fontColor);
	// DrawText(text, this->getPos().x + margin, this->getPos().y + margin, fontSize, fontColor);
	// get size of text
}

raylib::Color Button::getColor() { return color; }
void Button::setColor(raylib::Color color) { this->color = color; }
void Button::setText(std::string text) { this->text = text; }
std::string Button::getText() { return text; }
void Button::setMargin(int margin) { this->margin = margin; }
int Button::getMargin() { return margin; }
void Button::setFontSize(int fontSize) {}
int Button::getFontSize() { return fontSize; }
void Button::setFontColor(raylib::Color color) {}
raylib::Color Button::getFontColor() { return fontColor; }