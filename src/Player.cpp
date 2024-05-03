#include "Player.hpp"

float Player::speed = 20;

Player::Player(Game* game) : GameEntity(game) {}

void Player::Update(float dt) {
	// Move around using arrow keys scaled by speed and dt
	raylib::Vector2 movement = raylib::Vector2(0, 0);
	if (IsKeyDown(KEY_LEFT)) {
		movement.x--;
	}
	if (IsKeyDown(KEY_UP)) {
		movement.y--;
	}
	if (IsKeyDown(KEY_DOWN)) {
		movement.y++;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		movement.x++;
	}
	raylib::Vector2 pos = get_pos();
	set_pos(pos + movement.Normalize() * dt * speed);
}

// TODO: Replace this with a sprite and animations
void Player::Draw() {
	DrawCircleV(get_pos(), 20, BLACK);
}