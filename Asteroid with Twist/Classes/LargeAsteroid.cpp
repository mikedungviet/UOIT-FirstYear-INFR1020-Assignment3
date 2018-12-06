#include "LargeAsteroid.h"
#include "SmallAsteroid.h"
#include "GameEntitiesSingleton.h"

unsigned int LargeAsteroid::count = 0;
/*
 * @brief Constructor for Small Asteroid
 */
LargeAsteroid::LargeAsteroid():GameEntities("LargeAsteroid.png")
{
	SetPosition(rand() % 10000 + 500, rand() % 10000 + 500);
	pr_Movement->SetVelocity(Vector2(rand() % 200 - 100, rand() % 200 - 100));
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
	count++;
}

LargeAsteroid::~LargeAsteroid()
{
	count--;
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
		auto lo_Temp1 = new SmallAsteroid(pr_Collision->GetPosition());
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

void LargeAsteroid::ResolveCollision(EnemyBullet* ar_Bullet)
{
	pr_Lives--;
	
}

void LargeAsteroid::ResolveCollision(PlannetEnemy* ar_Planet)
{
	pr_Lives--;
}
