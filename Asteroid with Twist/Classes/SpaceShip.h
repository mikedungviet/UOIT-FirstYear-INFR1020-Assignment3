#pragma once
#include "GameEntities.h"
#include "State.h"

class SpaceShip :
	public GameEntities
{
private:
	SpaceShipState *pr_CurrentState;
	const float pr_Speed;
public:
	//Constructors and Destructor
	SpaceShip();
	~SpaceShip();

	//Setters
	void SetState(SpaceShipState *ar_NewState);

	//Member Functions
	void Update(const float& ar_DeltaTime) override;
	void ChangeToNormalState();
	void ChangeToSpinState();

	//Movement
	void ApplyForceForward() ;
	void ApplyForceBackward();
	void ApplyForceLeft();
	void ApplyForceRight();
	void RotateLeft();
	void RotateRight();
	
};
