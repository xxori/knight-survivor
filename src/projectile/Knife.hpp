#pragma once

#include "./Projectile.hpp"

// A knife projectile that shoots rapidly and travels in a straight line
class Knife : public Projectile {
private:
	raylib::Vector2 dir;

public:
	Knife(Game* game, float speed, int damage, raylib::Vector2 dir);
	void update(float dt) override;
	void draw() override;
};