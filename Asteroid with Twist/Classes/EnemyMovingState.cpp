#include "EnemyMovingState.h"
#include "Enemies.h"
#include "EnemyShootingState.h"


EnemyMovingState::EnemyMovingState(Enemies *ar_Enemy)
{
	//Give a random velocity
	Vector2 lo_RandomVelocity(200, 0);
	pr_Enemy = ar_Enemy;
	pr_Enemy->GetMovementComponent()->SetVelocity(lo_RandomVelocity);
	pr_Enemy->ChangeEntityDirection(lo_RandomVelocity);
}


EnemyMovingState::~EnemyMovingState()
{
}

void EnemyMovingState::Update(const float& ar_DeltaTime)
{
	pr_Enemy->GameEntities::Update(ar_DeltaTime);
}

void EnemyMovingState::ChangeToShootingState()
{
	pr_Enemy->SetState(new EnemyShootingState(pr_Enemy));
	delete this;
}


