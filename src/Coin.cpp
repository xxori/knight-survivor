#include "Coin.hpp"
#include "Game.hpp"

Coin::Coin(Game* game, raylib::Vector2 pos) : GameEntity(game, pos, raylib::Rectangle(0, 0, 10, 10)) {}

void Coin::update(float dt) {
	Player* player = getGame()->getPlayer();
	raylib::Vector2 playerPos = player->getCenter();

	// For convenience, the coin is attractd to the player if near
	if ((getPos() - playerPos).Length() < 60.0) {
		raylib::Vector2 dir = (playerPos - getPos()).Normalize();
		setPos(getPos() + dir * dt * 250);
	}

	// The player picks up the coin if colliding
	if (collide(player)) {
		player->setXp(player->getXp() + 1);
		return getGame()->removeObject(this);
	}
}

void Coin::draw() {
	// The coin is simply an orange circle
	DrawCircleV(getCenter(), 5, ORANGE);
}