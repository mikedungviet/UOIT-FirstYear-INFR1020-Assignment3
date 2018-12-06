#pragma once
#include "GameEntities.h"
class LargeAsteroid:
	public GameEntities
{
public:
	LargeAsteroid();
	~LargeAsteroid();

	static unsigned int count;
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(ShipBullet* ar_Bullet) override;
	void ResolveCollision(SpaceShip* ar_SpaceShip) override;
	void ResolveCollision(GrapplingHookBullet* ar_Hook) override;
	void ResolveCollision(EnemyBullet* ar_Bullet) override;
	void ResolveCollision(PlannetEnemy *ar_Planet) override;
};