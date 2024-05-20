#include "common/GameEntity.hpp"

class Coin : public GameEntity {
public:
	Coin(Game* game, raylib::Vector2 pos);
	void update(float dt) override;
	void draw() override;
};