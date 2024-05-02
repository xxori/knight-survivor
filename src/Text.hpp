#ifndef TEXT_HPP
#define TEXT_HPP
#include "GameEntity.hpp"

class Text : public GameEntity {
    protected:
        std::string text;
        int size;
        raylib::Color color;
    public:
        Text();
        Text(std::string text, raylib::Vector2 pos, int size, raylib::Color color);
        void Update(float dt);
        void Draw();
};

#endif