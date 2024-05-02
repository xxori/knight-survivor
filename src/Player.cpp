#include "Player.hpp"

float Player::speed = 20;

Player::Player(Game* game) : GameEntity(game) {}

void Player::Update(float dt) {
    // Move around using arrow keys scaled by speed and dt
	if (IsKeyDown(KEY_LEFT)) {
		raylib::Vector2 pos = get_pos();
		set_pos(raylib::Vector2(pos.x - speed * dt, pos.y));
	}
	if (IsKeyDown(KEY_UP)) {
		raylib::Vector2 pos = get_pos();
		set_pos(raylib::Vector2(pos.x, pos.y - speed * dt));
	}
	if (IsKeyDown(KEY_DOWN)) {
		raylib::Vector2 pos = get_pos();
		set_pos(raylib::Vector2(pos.x, pos.y + speed * dt));
	}
	if (IsKeyDown(KEY_RIGHT)) {
		raylib::Vector2 pos = get_pos();
		set_pos(raylib::Vector2(pos.x + speed * dt, pos.y));
	}
}

// TODO: Replace this with a sprite and animations
void Player::Draw() {
	DrawCircleV(get_pos(), 20, BLACK);
}