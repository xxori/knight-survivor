#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP
#include "raylib-cpp.hpp" // IWYU pragma: keep

class GameEntity {
    protected:
        raylib::Vector2 pos;
    public:
        virtual void Update(float dt);
        virtual void Draw();
};

#endif