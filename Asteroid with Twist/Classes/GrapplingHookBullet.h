#pragma once
#include "GameEntities.h"
#include "GameEntitiesSingleton.h"

class SpaceShip;

class GrapplingHookBullet :
	public GameEntities
{
private:
	float pr_LifeTime;
public:
	GrapplingHookBullet(const SpaceShip * ar_Ship);
	~GrapplingHookBullet();

	//Member Functions
	void Update(const float& ar_DeltaTime) override;

	//Collision Detection
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(SmallAsteroid* ar_SmallAsteroid) override;
	void ResolveCollision(PlannetEnemy* ar_Planet) override;
	void ResolveCollision(LargeAsteroid* ar_Asteroid) override;
};

