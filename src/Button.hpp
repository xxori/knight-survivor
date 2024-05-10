#pragma once

#include "GameObject.hpp"

class Button : public GameObject {
private:
    std::string text;
    int margin;
    int fontSize;
    raylib::Color fontColor;
    raylib::Color color;
    // eventually won't need these
    // draw text, get size of text, draw button rectangle behind it
    int height;
    int width;
public:
    Button(Game* game);
    Button(Game* game, raylib::Vector2 pos, int height, int width, raylib::Color color, std::string text, int margin, int fontSize, raylib::Color fontColor);
    
    void update(float dt);
	void draw();

    raylib::Color getColor();
    void setColor(raylib::Color color);
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
    void setText(std::string text);
    std::string getText();
    void setMargin(int margin);
    int getMargin();
    void setFontSize(int fontSize);
    int getFontSize();
    void setFontColor(raylib::Color color);
    raylib::Color getFontColor();
};