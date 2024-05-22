#include "common/GameEntity.hpp"

// A coin dropped from dead enemies that gives player xp
class Coin : public GameEntity {
public:
	Coin(Game* game, raylib::Vector2 pos);
	void update(float dt) override;
	void draw() override;
};