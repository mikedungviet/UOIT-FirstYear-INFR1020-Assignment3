#pragma once
#include "GameEntities.h"
class PowerUps :
	public GameEntities
{
public:
	PowerUps();
	PowerUps(const Vector2 *ar_Position);
	~PowerUps();

	void ResolveCollision(GameEntities *ar_Entities) override;
	void ResolveCollision(SpaceShip* ar_SpaceShip) override;
};

