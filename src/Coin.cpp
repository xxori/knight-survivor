#include "Coin.hpp"
#include "Game.hpp"

Coin::Coin(Game* game, raylib::Vector2 pos) : GameEntity(game, pos, raylib::Rectangle(0, 0, 10, 10)) {}

void Coin::update(float dt) {
	Player* player = getGame()->getPlayer();
	raylib::Vector2 playerPos = player->getCenter();

	if ((getPos() - playerPos).Length() < 60.0) {
		raylib::Vector2 dir = (playerPos - getPos()).Normalize();
		setPos(getPos() + dir * dt * 250);
	}

	if (collide(player)) {
		player->setXp(player->getXp() + 1);
		return getGame()->removeObject(this);
	}
}

void Coin::draw() {
	DrawCircleV(getCenter(), 5, ORANGE);
}