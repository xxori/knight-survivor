#include "Player.hpp"
#include "Game.hpp"
#include "weapon/FireStaff.hpp"
#include "weapon/KnifeThrower.hpp"
#include "weapon/MissileBook.hpp"
#include <iostream>
#include <raylib-cpp.hpp>
#include <raylib.h>

Player::Player(Game* game) : GameEntity(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 40, 40)), speed(125.0), weapons(), level(1), experience(0) {
	addRandomWeapon();
	// weapons.push_back(new FireStaff(game, 5));
	// weapons.push_back(new KnifeThrower(game, 0.5));
	// weapons.push_back(new MissileBook(game, 3));
	invincibility = 3.0;
	timeToDamage = invincibility;
	health = 10;
	direction = raylib::Vector2(1, 0);
}
Player::~Player() {
	for (auto weapon : weapons) {
		delete weapon;
	}
}

void Player::addRandomWeapon() {
	switch (GetRandomValue(1, 3)) {
		case 1:
			weapons.push_back(new FireStaff(getGame(), 5));
			break;
		case 2:
			weapons.push_back(new KnifeThrower(getGame(), 0.5));
			break;
		case 3:
			weapons.push_back(new MissileBook(getGame(), 5));
			break;
	}
}

int Player::getXp() { return experience; }
void Player::setXp(int xp) { experience = xp; }
int Player::getLevel() { return level; }

void Player::setDirection(raylib::Vector2 dir) {
	direction = dir;
}

raylib::Vector2 Player::getDirection() {
	return direction;
}

void Player::update(float dt) {

	if (timeToDamage > 0)
		timeToDamage -= dt;

	if (experience > level * 5) {
		level += 1;
		experience = 0;
		health += 1;
		if (speed < 300) {
			speed += 15;
		}
		addRandomWeapon();
		std::cout << "Level Up\n";
	}

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
	// just to test death menu, remove later
	if (IsKeyDown(KEY_P)) {
		health = 0;
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
		if (health <= 0) {
			getGame()->setState(Dead);
		}
		std::cout << "Player took " << damage << " damage leaving them with " << health << " health" << std::endl;
	}
}

// TODO: Replace this with a sprite and animations
void Player::draw() {
	DrawCircleV(getPos() + raylib::Vector2(20, 20), 20, BLACK);
	// Uncomment to show collider
	// DrawRectangleLinesEx(getCollider(), 1, raylib::Color::Red());
}

void Player::resetHealth() {
	health = 10;
	level = 1;
	speed = 125;
	experience = 0;
}

void Player::resetWeapons(Game* game) {
	for (auto weapon : weapons) {
		delete weapon;
	}
	weapons = {};
	addRandomWeapon();
}

int Player::getHealth() {
	return health;
}

float Player::getSpeed() {
	return speed;
}