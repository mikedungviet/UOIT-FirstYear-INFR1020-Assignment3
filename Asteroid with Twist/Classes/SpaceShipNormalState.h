#pragma once
#include "State.h"

class SpaceShipNormalState : public SpaceShipState
{
public:
	SpaceShipNormalState();
	~SpaceShipNormalState();

	void Update(const float& ar_DeltaTime, SpaceShip* ar_Entity) const override;
	void ChangeToSpinState(SpaceShip* ar_Entity) const override;
};

