#include "LargeAsteroid.h"
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
	//Sprite *newLAsteroid = new Sprite(*largeAsteroidDefault);
	//if (rand() % 2)
	//{
	//	newLAsteroid->setPosition(rand() % 1920, -40);
	//}
	//else
	//{
	//	newLAsteroid->setPosition(-40, rand() % 1080);
	//}

	////newLAsteroid->velocity = Vector3(100, 100, 0.0f) * 300;
	//newLAsteroid->velocity = Vector3(rand() % 500 - 250, rand() % 500 - 250, 0);
	//largeAsteroids.push_back(newLAsteroid);
	//this->addSpriteToDrawList(newLAsteroid);
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

