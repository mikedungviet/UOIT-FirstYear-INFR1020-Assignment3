#pragma once
#include "State.h"

class SpaceShipSpinState :
	public SpaceShipState
{
private:
	mutable float pr_TotalTime;
public:
	SpaceShipSpinState();
	~SpaceShipSpinState();

	//Member Functions
	void Update(const float& ar_DeltaTime, SpaceShip* ar_Entity) const override;
	void ChangeToNormalState(SpaceShip *ar_Entity) const override;
};

