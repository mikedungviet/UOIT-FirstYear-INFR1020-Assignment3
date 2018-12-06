#include "Boss.h"
#include "GameEntitiesSingleton.h"
#include "EnemyStandStillState.h"


Boss::Boss() :Enemies("Boss.png")
{
	SetPosition(5000, 5000);
	pr_CurrentState = new EnemyStandStillState(this);
	pr_ActionRange = 100;
	Health = 100;
	pr_Lives = 3;
}

Boss::~Boss()
{
}

void Boss::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime);
}

void Boss::ChangeToIdleState()
{
	pr_CurrentState->ChangeToStandStillState();
}

void Boss::ChangeToActionState()
{
	pr_CurrentState->ChangeToShootingState();
}

void Boss::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

void Boss::ResolveCollision(ShipBullet* ar_Bullet)
{
	Health--;
	if (Health == 0)
	{
		pr_Lives--;
		Health = 100;
		pr_ActionRange += 100;
	}
}
