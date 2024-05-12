#include "Button.hpp"

Button::Button(Game* game) : Button(game, raylib::Vector2(0, 0), WHITE, "", 0, 0, WHITE) {}

Button::Button(Game* game, raylib::Vector2 pos, raylib::Color color, std::string text, int margin, int fontSize, raylib::Color fontColor) : GameObject(game, pos), color(color), text(text), margin(margin), fontSize(fontSize), fontColor(fontColor) {}

void Button::update(float dt) {
	raylib::Vector2 mousePos = GetMousePosition();
	int width = MeasureText(text.c_str(), fontSize);

	if (mousePos.x >= this->getPos().x && mousePos.y >= this->getPos().y && mousePos.x <= this->getPos().x + width + 2 * margin && mousePos.y <= this->getPos().y + fontSize + 2 * margin) { // if mouseclick inside button area
																																																																																													 // do something
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			// If clicked
			this->setText("Clicked");
		} else {
			// If hovered
			this->setColor(raylib::Color::FromHSV(0, 68, 100));
		}
	} else {
		// Reset color
		this->setColor(RED);
	}
}

void Button::draw() {
	int width = MeasureText(text.c_str(), fontSize);
	DrawRectangle(this->getPos().x, this->getPos().y, width + 2 * margin, fontSize + 2 * margin, color);
	DrawText(text, this->getPos().x + margin, this->getPos().y + margin, fontSize, fontColor);
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