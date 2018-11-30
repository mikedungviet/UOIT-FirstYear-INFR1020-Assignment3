#pragma once

extern class SpaceShip;

class GunMode
{
public:
	~GunMode();

	virtual void ShootBullets(const SpaceShip *ar_Ship) = 0;
	virtual void ChangeToNormalMode(SpaceShip *ar_Ship);
	virtual void ChangeToHookMode(SpaceShip *ar_Ship);
};

