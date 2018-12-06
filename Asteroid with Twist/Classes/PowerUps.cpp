#include "PowerUps.h"
#include "SmallAsteroid.h"
#include "GameEntitiesSingleTon.h"

PowerUps::PowerUps() : GameEntities("PowerUp.png")
{
	SetPosition(1000, 1000);
	pr_Movement->SetVelocity(0, 0);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

PowerUps::PowerUps(const Vector2 *ar_Position): GameEntities("PowerUp.png")
{
	SetPosition(*ar_Position);
	pr_Movement->SetVelocity(0, 0);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

PowerUps::~PowerUps()
{

}

void PowerUps::ResolveCollision(GameEntities * ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

void PowerUps::ResolveCollision(SpaceShip* ar_SpaceShip)
{
	pr_Lives -= 1;
}