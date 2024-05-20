#pragma once

#include "Weapon.hpp"

class MissileBook : public Weapon {

public:
	MissileBook(Game* game, float firespeed);
	void update(float dt) override;
};