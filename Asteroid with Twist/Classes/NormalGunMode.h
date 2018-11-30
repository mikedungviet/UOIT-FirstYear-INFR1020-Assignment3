#pragma once
#include "GunMode.h"
class NormalGunMode :
	public GunMode
{
public:
	NormalGunMode();
	~NormalGunMode();

	void ShootBullets(const SpaceShip* ar_Ship) override;
	void ChangeToHookMode(SpaceShip* ar_Ship) override;
};

