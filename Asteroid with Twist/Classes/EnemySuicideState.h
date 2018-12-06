#pragma once
#include "EnemyState.h"
#include "CollisionComponent.h"

class EnemySuicideState :
	public EnemyState
{
private:
	CollisionComponent *pr_SpaceShipCollisionComponent;
public:
	EnemySuicideState(Enemies *ar_Enemy);
	~EnemySuicideState();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToMovingState() override;
};

