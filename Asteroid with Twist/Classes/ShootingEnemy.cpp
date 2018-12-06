#include "ShootingEnemy.h"
#include "GameEntitiesSingleton.h"
#include "EnemyMovingState.h"

unsigned int ShootingEnemy::count = 0;
ShootingEnemy::ShootingEnemy():Enemies("EnemyShootingShip.png")
{
	SetPosition(rand() % 10000 + 500, rand() % 10000 + 500);
	pr_CurrentState = new EnemyMovingState(this);
	pr_ActionRange = 300;
}


ShootingEnemy::~ShootingEnemy()
{
	count--;
}

void ShootingEnemy::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime);
}

void ShootingEnemy::ChangeToIdleState()
{
	pr_CurrentState->ChangeToMovingState();
}

void ShootingEnemy::ChangeToActionState()
{
	pr_CurrentState->ChangeToShootingState();
}

void ShootingEnemy::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

void ShootingEnemy::ResolveCollision(SpaceShip* ar_Ship)
{
	pr_Lives--;
}

void ShootingEnemy::ResolveCollision(ShipBullet* ar_Bullet)
{
	pr_Lives--;
}



