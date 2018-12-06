#include "EnemyStandStillState.h"
#include "Enemies.h"
#include "EnemyShootingState.h"


EnemyStandStillState::EnemyStandStillState(Enemies *ar_Enemy)
{
	pr_Enemy = ar_Enemy;
	pr_Enemy->GetMovementComponent()->SetVelocity(0, 0);
}


EnemyStandStillState::~EnemyStandStillState()
{
}

void EnemyStandStillState::Update(const float& ar_DeltaTime)
{
	return;
}


void EnemyStandStillState::ChangeToShootingState()
{
	pr_Enemy->SetState(new EnemyShootingState(pr_Enemy));
	delete this;
}
