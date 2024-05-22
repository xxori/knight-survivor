#include "Player.hpp"
#include "Game.hpp"
#include "weapon/FireStaff.hpp"
#include "weapon/KnifeThrower.hpp"
#include "weapon/MissileBook.hpp"
#include <raylib-cpp.hpp>
#include <raylib.h>

Player::Player(Game* game) : GameEntity(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 40, 40)), speed(125.0), weapons(), level(1), experience(0) {

	// Initial values for player stats
	addRandomWeapon();
	invincibility = 1.0;
	timeToDamage = invincibility;
	health = 5;

	// Initially pointed to the right.
	direction = raylib::Vector2(1, 0);
}
Player::~Player() {
	// Cleanup all weapon pointers on game end.
	for (auto weapon : weapons) {
		delete weapon;
	}
}

void Player::addRandomWeapon() {
	// Use GetRandomValue to add one of our 3 weapons randomly.
	// Each weapon also takes a firespeed that can be tuned.
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

// Getters and setters to provide encapsulation and access for private variables
int Player::getXp() { return experience; }
void Player::setXp(int xp) { experience = xp; }
int Player::getLevel() { return level; }

void Player::setDirection(raylib::Vector2 dir) { direction = dir; }
raylib::Vector2 Player::getDirection() { return direction; }

int Player::getHealth() { return health; }

float Player::getSpeed() { return speed; }

// On taking damage, we need to additionally check for invincibility
// and trigger death if the player has 0 health.
void Player::takeDamage(int damage) {
	if (timeToDamage <= 0) {
		timeToDamage = invincibility;
		health -= damage;
		if (health <= 0) {
			getGame()->setState(Dead);
		}
	}
}

void Player::update(float dt) {

	// Count the invincibility timer down as time progresses
	if (timeToDamage > 0)
		timeToDamage -= dt;

	// If experience is greather than 5*level, then the player levels up
	if (experience >= level * 5) {
		level += 1;
		experience = 0;

		// The player gets stronger as they level up, healing one health,
		// gaining one speed (up to a cap), and a random weapon.
		health += 1;
		if (speed < 300) {
			speed += 15;
		}
		addRandomWeapon();
	}

	// Process each of our weapons to spawn new projectiles.
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
	// Normalise movement vector so moving diagonally isn't faster
	raylib::Vector2 dir = movement.Normalize();

	// Set direction if we are moving.
	if (dir.Length() != 0) {
		setDirection(dir);
	}
	setPos(pos + dir * dt * speed);
}

// The player is represented by a black circle with radius 20.
void Player::draw() {
	DrawCircleV(getPos() + raylib::Vector2(20, 20), 20, BLACK);
}

// When the player dies and respawns, we want to reset their stats and weapons.
void Player::resetStats() {
	health = 5;
	level = 1;
	speed = 125;
	experience = 0;
}

void Player::resetWeapons(Game* game) {
	for (auto weapon : weapons) {
		delete weapon;
	}
	weapons.clear();
	addRandomWeapon();
}
