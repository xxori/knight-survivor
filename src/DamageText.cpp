#include "DamageText.hpp"
#include "Game.hpp"
#include <string>

DamageText::DamageText(Game* game, int damage, raylib::Vector2 pos) : DamageText(game, damage, pos, 3.0) {}
DamageText::DamageText(Game* game, int damage, raylib::Vector2 pos, float lifespan) : Text(game, std::to_string(damage), pos, 18, RED), lifespan(lifespan) {}

void DamageText::update(float dt) {
	lifespan -= dt;
	if (lifespan <= 0)
		getGame()->removeObject(this);
}