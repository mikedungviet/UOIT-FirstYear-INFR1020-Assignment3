#include "EnemySuicideState.h"
#include "Enemies.h"
#include "EnemyMovingState.h"
#include "GameEntitiesSingleton.h"
#include "SpaceShip.h"



EnemySuicideState::EnemySuicideState(Enemies *ar_Enemy)
{
	pr_SpaceShipCollisionComponent = GameEntitiesSingleton::GetInstance()->GetSpaceShip()->GetCollisionComponent();
	pr_Enemy = ar_Enemy;

	ar_Enemy->GetMovementComponent()->SetVelocity(0, 0);
	
}


EnemySuicideState::~EnemySuicideState()
{
}

void EnemySuicideState::Update(const float& ar_DeltaTime)
{
	//Find the direction of from this object to the space ship
	auto lo_DirectionToShip = Vector2::CalculateNormalizedVector(Vector2(pr_SpaceShipCollisionComponent->GetPosition()->x - pr_Enemy->GetCollisionComponent()->GetPosition()->x,
		pr_SpaceShipCollisionComponent->GetPosition()->y - pr_Enemy->GetCollisionComponent()->GetPosition()->y));
	pr_Enemy->ChangeEntityDirection(lo_DirectionToShip);

	//Apply Force
	pr_Enemy->GetMovementComponent()->SetAppliedForce(150);

	//Update normally
	pr_Enemy->GetMovementComponent()->Update(ar_DeltaTime);

	


	pr_Enemy->GetCollisionComponent()->Update(ar_DeltaTime, pr_Enemy->GetMovementComponent()->GetVelocity());
	pr_Enemy->CheckPositionOutOfMap();
	pr_Enemy->GetSprite()->setPosition(pr_Enemy->GetCollisionComponent()->GetPosition()->x, pr_Enemy->GetCollisionComponent()
		->GetPosition()->y);
}

void EnemySuicideState::ChangeToMovingState()
{
	pr_Enemy->SetState(new EnemyMovingState(pr_Enemy));
	delete this;
}


