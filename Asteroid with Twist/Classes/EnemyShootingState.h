#pragma once
#include "EnemyState.h"
#include "CollisionComponent.h"

class EnemyShootingState :
	public EnemyState
{
private:
	const CollisionComponent *pr_SpaceShipCollisionComponent;
	int pr_BulletSpawningCounter;
public:
	EnemyShootingState(Enemies *ar_Enemy);
	~EnemyShootingState();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToMovingState() override;
};

