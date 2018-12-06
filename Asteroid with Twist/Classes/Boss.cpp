#include "Boss.h"
#include "GameEntitiesSingleton.h"
#include "EnemyMovingState.h"


Boss::Boss() :Enemies("EnemyShootingShip.png")
{
	SetPosition(500, 500);
	pr_CurrentState = new EnemyMovingState(this);
	pr_ActionRange = 600;
	pr_Lives = 50;
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
	pr_CurrentState->ChangeToMovingState();
}

void Boss::ChangeToActionState()
{
	pr_CurrentState->ChangeToShootingState();
}

void Boss::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}