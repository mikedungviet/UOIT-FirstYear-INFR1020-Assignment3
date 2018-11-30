#pragma once
#include "GunMode.h"

class SpaceShip;

class HookGunMode :
	public GunMode
{
private:
	int pr_NumberOfBullet;
public:
	HookGunMode();
	~HookGunMode();

	void ShootBullets(const SpaceShip* ar_Ship) override;
	void ChangeToNormalMode(SpaceShip* ar_Ship) override;

};

