#pragma once

class SpaceShip;

class SpaceShipState
{
public:
	~SpaceShipState();

	//Member Functions
	virtual void Update(const float &ar_DeltaTime, SpaceShip * ar_Entity) = 0;
	virtual void ChangeToNormalState(SpaceShip *ar_Entity) const;
	virtual void ChangeToSpinState(SpaceShip *ar_Entity) const;
	virtual void ChangeToHookState(SpaceShip *ar_Ship) const;

	//Movement from Input
	virtual void ApplyForceForward(SpaceShip *ar_Ship){}
	virtual void ApplyForceBackward(SpaceShip *ar_Ship){}
	virtual void ApplyForceLeft(SpaceShip *ar_Ship){}
	virtual void ApplyForceRight(SpaceShip *ar_Ship){}
	virtual void RotateLeft(SpaceShip *ar_Ship){}
	virtual void RotateRight(SpaceShip *ar_Ship){}
};

