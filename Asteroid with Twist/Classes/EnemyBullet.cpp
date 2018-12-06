#include "EnemyBullet.h"
#include "GameEntitiesSingleton.h"


EnemyBullet::EnemyBullet(): GameEntities("EnemyBullet.png"), pr_LifeTime(3.f)
{
	pr_Movement->SetAppliedForce(1000);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}


EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(const float& ar_DeltaTime)
{
	GameEntities::Update(ar_DeltaTime);
	pr_LifeTime -= ar_DeltaTime;
	if(pr_LifeTime<=0)
	{
		GameEntitiesSingleton::GetInstance()->DeleteEntity(this);
	}
}

void EnemyBullet::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

void EnemyBullet::ResolveCollision(PlannetEnemy* ar_Planet)
{
	pr_Lives--;
}

void EnemyBullet::ResolveCollision(SpaceShip* ar_Ship)
{
	pr_Lives--;
}
