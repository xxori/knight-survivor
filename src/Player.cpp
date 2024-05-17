#include "Player.hpp"
#include "weapon/FireStaff.hpp"
#include "weapon/KnifeThrower.hpp"
#include <raylib-cpp.hpp>

Player::Player(Game* game) : GameEntity(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 40, 40), nullptr), speed(100.0), weapons() {
	weapons.push_back(new FireStaff(game, 5));
	weapons.push_back(new KnifeThrower(game, 0.5));
	invincibility = 3.0;
	timeToDamage = invincibility;
	direction = raylib::Vector2(1, 0);
	health = 100;
}
Player::~Player() {
	for (auto weapon : weapons) {
		delete weapon;
	}
}

void Player::setDirection(raylib::Vector2 dir) {
	direction = dir;
}

raylib::Vector2 Player::getDirection() {
	return direction;
}

void Player::update(float dt) {

	if (timeToDamage > 0)
		timeToDamage -= dt;

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
	raylib::Vector2 dir = movement.Normalize();
	if (dir.Length() != 0) {
		setDirection(dir);
	}
	setPos(pos + dir * dt * speed);
}

void Player::takeDamage(int damage) {
	if (timeToDamage <= 0) {
		timeToDamage = invincibility;
		// Check for deaths here
		health -= damage;
	}
}

// TODO: Replace this with a sprite and animations
void Player::draw() {
	DrawCircleV(getPos() + raylib::Vector2(20, 20), 20, BLACK);
	// Uncomment to show collider
	// DrawRectangleLinesEx(getCollider(), 1, raylib::Color::Red());
}