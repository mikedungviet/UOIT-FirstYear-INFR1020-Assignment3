#pragma once
#include "GameEntities.h"
class SmallAsteroid :
	public GameEntities
{
public:
	SmallAsteroid();
	~SmallAsteroid();

	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(ShipBullet* ar_Bullet) override;
	void ResolveCollision(SpaceShip* ar_SpaceShip) override;
	void ResolveCollision(GrapplingHookBullet* ar_Hook) override;
};

