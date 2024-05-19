#pragma once

#include "Weapon.hpp"

class KnifeThrower : public Weapon {
public:
	KnifeThrower(Game* game, float firespeed);
	void update(float dt) override;
};