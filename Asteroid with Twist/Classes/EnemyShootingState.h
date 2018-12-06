#pragma once
#include "EnemyState.h"
#include "CollisionComponent.h"

class EnemyShootingState :
	public EnemyState
{
private:
	const CollisionComponent *pr_SpaceShipCollisionComponent;
	int pr_BulletSpawningCounter, pr_ShotSpeed;
public:
	EnemyShootingState(Enemies *ar_Enemy, const int &ar_ShootSpeed = 250);
	~EnemyShootingState();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToMovingState() override;
	void ChangeToStandStillState() override;
};

