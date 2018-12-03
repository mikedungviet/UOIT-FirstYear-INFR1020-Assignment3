#pragma once
#include "State.h"

class SpaceShipNormalState : public SpaceShipState
{
private:
	float pr_Friction;
public:
	SpaceShipNormalState();
	~SpaceShipNormalState();

	void Update(const float& ar_DeltaTime, SpaceShip* ar_Entity) override;
	void ChangeToSpinState(SpaceShip* ar_Entity) const override;
	void ChangeToHookState(SpaceShip* ar_Ship) const override;

	//Movement
	void ApplyForceForward(SpaceShip *ar_Ship) override;
	void ApplyForceBackward(SpaceShip *ar_Ship) override;
	void ApplyForceLeft(SpaceShip *ar_Ship) override;
	void ApplyForceRight(SpaceShip *ar_Ship) override;
	void RotateLeft(SpaceShip* ar_Ship) override;
	void RotateRight(SpaceShip* ar_Ship) override;
};

