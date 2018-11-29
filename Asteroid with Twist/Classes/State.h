#pragma once
#include "GameEntities.h"

extern class SpaceShip;

class SpaceShipState
{
public:
	~SpaceShipState();

	//Member Functions
	virtual void Update(const float &ar_DeltaTime, SpaceShip * ar_Entity) const = 0;
	virtual void ChangeToNormalState(SpaceShip *ar_Entity) const;
	virtual void ChangeToSpinState(SpaceShip *ar_Entity) const;
};

