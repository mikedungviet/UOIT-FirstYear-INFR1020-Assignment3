#pragma once
#include "State.h"

class SpaceShipNormalState : public State
{
public:
	SpaceShipNormalState();
	~SpaceShipNormalState();

	void Update(const float& ar_DeltaTime, const MovementComponent* ar_Movement, 
		 CollisionComponent* ar_Collision) const override;
	//void ChangeToSpecialState();
};

