#include "LargeAsteroid.h"
#include "SmallAsteroid.h"
#include "GameEntitiesSingleton.h"

/*
 * @brief Constructor for Small Asteroid
 */
LargeAsteroid::LargeAsteroid():GameEntities("LargeAsteroid.png")
{
	SetPosition(500, 500);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

LargeAsteroid::~LargeAsteroid()
{

}


void LargeAsteroid::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

/*
 * @brief
 */
void LargeAsteroid::ResolveCollision(ShipBullet* ar_Bullet)
{
	pr_Lives -= 1;
	for(int i = 0 ; i < rand() % 4 + 2 ; i ++)
	auto lo_Temp1 = new SmallAsteroid(this->GetCollisionComponent()->GetPosition());
}

/*
 * @brief 
 */
void LargeAsteroid::ResolveCollision(SpaceShip* ar_SpaceShip)
{
	pr_Lives -= 1;
}

/*
 *
 */
void LargeAsteroid::ResolveCollision(GrapplingHookBullet* ar_Hook)
{
	pr_Movement->SetVelocity(0, 0);
	GameEntitiesSingleton::GetInstance()->SetHookedAsteroidPosition(pr_Collision->GetPosition());
}

void LargeAsteroid::ResolveCollision(SmallAsteroid* ar_SmallAsteroid)
{

}
void LargeAsteroid::ResolveCollision(LargeAsteroid* ar_LargeAsteroid)
{

}