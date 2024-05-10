#include "Button.hpp"

Button::Button(Game* game) : Button(game, raylib::Vector2(0, 0), 0, 0, WHITE, "", 0, 0, WHITE) {}

Button::Button(Game* game, raylib::Vector2 pos, int height, int width, raylib::Color color, std::string text, int margin, int fontSize, raylib::Color fontColor) : GameObject(game, pos), height(height), width(width), color(color), text(text), margin(margin), fontSize(fontSize), fontColor(fontColor) {}
    
void Button::update(float dt) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        raylib::Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= this->getPos().x && mousePos.x <= this->getPos().x + width
        && mousePos.y >= this->getPos().y && mousePos.y <= this->getPos().y + height) { // if mouseclick inside button area
            // do something
            text = "Clicked";
        }
    }
}

void Button::draw() {
    DrawRectangle(this->getPos().x, this->getPos().y, width, height, color);
    DrawText(text, this->getPos().x + margin, this->getPos().y + margin, fontSize, fontColor);
}

raylib::Color Button::getColor() { return color; }
void Button::setColor(raylib::Color color) { this->color = color; }
int Button::getHeight() { return height; }
void Button::setHeight(int height) { this->height = height; }
int Button::getWidth() { return width; }
void Button::setWidth(int width) { this->width = width; }
void Button::setText(std::string text) { this->text = text; }
std::string Button::getText() { return text; }
void Button::setMargin(int margin) { this->margin = margin; }
int Button::getMargin() { return margin; }
void Button::setFontSize(int fontSize) {}
int Button::getFontSize() { return fontSize; }
void Button::setFontColor(raylib::Color color) {}
raylib::Color Button::getFontColor() { return fontColor; }