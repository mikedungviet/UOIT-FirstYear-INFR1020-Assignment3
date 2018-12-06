#include "PlannetEnemy.h"
#include "EnemyStandStillState.h"


PlannetEnemy::PlannetEnemy(): Enemies("Planet.png")
{
	pr_CurrentState = new EnemyStandStillState(this);
	pr_ActionRange = 1000;
}


PlannetEnemy::~PlannetEnemy()
{
}

void PlannetEnemy::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime);
}

void PlannetEnemy::ChangeToIdleState()
{
	pr_CurrentState->ChangeToStandStillState();
}

void PlannetEnemy::ChangeToActionState()
{
	pr_CurrentState->ChangeToShootingState();
}

void PlannetEnemy::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

