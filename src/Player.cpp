#include "Player.hpp"
#include "FireStaff.hpp"
#include <raylib.h>

Player::Player(Game* game) : GameEntity(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 40, 40), nullptr), speed(100.0), weapons() {
	weapons.push_back(new FireStaff(game, 5));
}
Player::~Player() {
	for (auto weapon : weapons) {
		delete weapon;
	}
}
void Player::update(float dt) {

	for (auto weapon : weapons) {
		weapon->update(dt);
	}

	// Move around using arrow keys scaled by speed and dt
	raylib::Vector2 movement = raylib::Vector2(0, 0);
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
		movement.x--;
	}
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
		movement.y--;
	}
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
		movement.y++;
	}
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
		movement.x++;
	}
	raylib::Vector2 pos = getPos();
	setPos(pos + movement.Normalize() * dt * speed);
}

// TODO: Replace this with a sprite and animations
void Player::draw() {
	DrawCircleV(getPos() + raylib::Vector2(20, 20), 20, BLACK);
	// Uncomment to show collider
	// DrawRectangleLinesEx(getCollider(), 1, raylib::Color::Red());
}