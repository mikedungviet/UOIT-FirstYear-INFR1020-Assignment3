#pragma once
#include "GameEntities.h"

extern class SpaceShip;

class ShipBullet: public GameEntities
{
private:
	float pr_LifeTime;
public:
	ShipBullet(const SpaceShip *ar_Ship);
	~ShipBullet();

	//Member functions
	void Update(const float& ar_DeltaTime) override;

	//Collision Resolver
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(SmallAsteroid* ar_SmallAsteroid) override;
	void ResolveCollision(LargeAsteroid* ar_LargeAsteroid) override;
};

