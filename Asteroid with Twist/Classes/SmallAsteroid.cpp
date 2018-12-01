#include "SmallAsteroid.h"
#include "GameEntitiesSingleton.h"

/*
 * @brief Constructor for Small Asteroid
 */
SmallAsteroid::SmallAsteroid():GameEntities("SmallAsteroid.png")
{
	SetPosition(500, 500);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

SmallAsteroid::~SmallAsteroid()
{
}


void SmallAsteroid::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

/*
 * @brief
 */
void SmallAsteroid::ResolveCollision(ShipBullet* ar_Bullet)
{
	pr_Lives -= 1;
}

/*
 * @brief 
 */
void SmallAsteroid::ResolveCollision(SpaceShip* ar_SpaceShip)
{
	pr_Lives -= 1;
}

/*
 *
 */
void SmallAsteroid::ResolveCollision(GrapplingHookBullet* ar_Hook)
{
	pr_Lives -= 1;
}

