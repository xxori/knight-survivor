#pragma once

#include "GameObject.hpp"

class Button : public GameObject {
private:
    // maybe just store a text object in here?
    //std::string text;
    //int fontSize;
    raylib::Color color;
    int height;
    int width;
public:
    Button(Game* game);
    Button(Game* game, raylib::Vector2 pos, int height, int width, raylib::Color color);
    
    void update(float dt);
	void draw();

    raylib::Color getColor();
    void setColor(raylib::Color color);
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
};