#include "NormalGunMode.h"
#include "ShipBullet.h"
#include "SpaceShip.h"
#include "HookGunMode.h"


NormalGunMode::NormalGunMode()
{
}


NormalGunMode::~NormalGunMode()
{
}

/*
 *
 */
void NormalGunMode::ShootBullets(const SpaceShip* ar_Ship)
{
	auto lo_TempBullet = new ShipBullet(ar_Ship);
}

/*
 *
 */
void NormalGunMode::ChangeToHookMode(SpaceShip* ar_Ship)
{
	ar_Ship->SetGunMode(new HookGunMode);
	delete this;
}
