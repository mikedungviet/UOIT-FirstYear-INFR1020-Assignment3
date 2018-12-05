#pragma once
#include "EnemyState.h"
#include "Vector2.h"

class EnemyMovingState:public EnemyState
{
private:
	Vector2 pr_RandomVelocity;
public:
	EnemyMovingState(Enemies *ar_Enemy);
	~EnemyMovingState();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToShootingState() override;
};

