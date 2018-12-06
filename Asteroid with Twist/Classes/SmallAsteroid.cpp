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

SmallAsteroid::SmallAsteroid(const Vector2 *ar_Position) :GameEntities("SmallAsteroid.png")
{
	SetPosition(*ar_Position);
	pr_Movement->SetVelocity(Vector2(rand() % 300 - 100, rand() % 300 - 100));
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
	pr_Movement->SetVelocity(0, 0);
	GameEntitiesSingleton::GetInstance()->SetHookedAsteroidPosition(pr_Collision->GetPosition());
}

void SmallAsteroid::ResolveCollision(EnemyBullet* ar_EnemyBullet)
{
	pr_Lives--;
}

