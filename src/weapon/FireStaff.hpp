#pragma once

#include "Weapon.hpp"

class FireStaff : public Weapon {
public:
	FireStaff(Game* game, float firespeed);
	void update(float dt) override;
};