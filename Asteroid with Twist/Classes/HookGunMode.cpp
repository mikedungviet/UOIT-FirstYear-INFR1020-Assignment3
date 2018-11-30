#include "HookGunMode.h"
#include "GrapplingHookBullet.h"
#include "SpaceShip.h"
#include "NormalGunMode.h"

HookGunMode::HookGunMode(): pr_NumberOfBullet(1){/*Empty*/}


HookGunMode::~HookGunMode()
{
}

/*
 * @brief 
 */
void HookGunMode::ShootBullets(const SpaceShip* ar_Ship)
{
	if (pr_NumberOfBullet == 0)
		return;
	
	auto lo_TempBullet = new GrapplingHookBullet(ar_Ship);
	pr_NumberOfBullet--;
}

/*
 *
 */
void HookGunMode::ChangeToNormalMode(SpaceShip* ar_Ship)
{
	ar_Ship->SetGunMode(new NormalGunMode);
	delete this;
}


