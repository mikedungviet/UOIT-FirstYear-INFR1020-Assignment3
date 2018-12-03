#pragma once
#include "State.h"
#include "Vector2.h"

class SpaceShipHookState :
	public SpaceShipState
{
private:
	float pr_DistanceToAsteroid, pr_Friction; //Radius
	mutable Vector2 pr_CentripetalDirection;

	//Member functions
	Vector2 FindPerpendicularVectorCounterClockWise(Vector2 & ar_Vector2);
public:
	SpaceShipHookState();
	~SpaceShipHookState();

	//Member functions
	void Update(const float& ar_DeltaTime, SpaceShip* ar_Entity) override;
	void ChangeToNormalState(SpaceShip* ar_Entity) const override;
	

	//Movement
	void ApplyForceForward(SpaceShip* ar_Ship) override;
	void ApplyForceBackward(SpaceShip* ar_Ship) override;
};

