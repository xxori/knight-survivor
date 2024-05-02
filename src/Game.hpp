#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include "raylib-cpp.hpp" // IWYU pragma: keep
#include "GameEntity.hpp"

class Game {
    private:
        std::vector<GameEntity*> entities;
        float dt;
    public:
        Game();
        ~Game();
        void UpdateAll();
        void DrawAll();
        void AddEntity(GameEntity *entity);
};

#endif