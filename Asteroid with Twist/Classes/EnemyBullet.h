#pragma once
#include "GameEntities.h"

class EnemyBullet :
	public GameEntities
{
private:
	float pr_LifeTime;
public:
	EnemyBullet();
	~EnemyBullet();

	void Update(const float& ar_DeltaTime) override;

	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(PlannetEnemy* ar_Planet) override;
};

