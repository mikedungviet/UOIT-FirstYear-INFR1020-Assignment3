#include "NormalGunMode.h"
#include "ShipBullet.h"
#include "SpaceShip.h"


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
	auto lo_Temp = new ShipBullet(ar_Ship);
}

/*
 *
 */
void NormalGunMode::ChangeToHookMode(SpaceShip* ar_Ship)
{
	//ar_Ship->SetGunMode(new )
}
