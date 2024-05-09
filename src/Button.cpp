#include "Button.hpp"

Button::Button(Game* game) : Button(game, raylib::Vector2(0, 0), 0, 0, WHITE) {}

Button::Button(Game* game, raylib::Vector2 pos, int height, int width, raylib::Color color) : GameObject(game, pos), height(height), width(width), color(color) {}
    
void Button::update(float dt) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        raylib::Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= this->getPos().x && mousePos.x <= this->getPos().x + width
        && mousePos.y >= this->getPos().y && mousePos.y <= this->getPos().y + height) { // if mouseclick inside button area
            // do something
            setHeight(height + 10);
            setWidth(width + 10);
        }
    }
}

void Button::draw() {
    DrawRectangle(this->getPos().x, this->getPos().y, width, height, color);
}

raylib::Color Button::getColor() { return color; }
void Button::setColor(raylib::Color color) { this->color = color; }
int Button::getHeight() { return height; }
void Button::setHeight(int height) { this->height = height; }
int Button::getWidth() { return width; }
void Button::setWidth(int width) { this->width = width; }
