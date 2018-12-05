#pragma once
#include "GameEntities.h"
class PowerUps :
	public GameEntities
{
public:
	PowerUps(const Vector2 *ar_Position);
	~PowerUps();


	void ResolveCollision(SpaceShip* ar_SpaceShip) override;
};

