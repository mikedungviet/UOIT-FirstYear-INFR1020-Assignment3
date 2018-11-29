#pragma once
#include "GameEntities.h"
#include "State.h"

class SpaceShip :
	public GameEntities
{
private:
	State *pr_CurrentState;
public:
	//Constructors and Destructor
	SpaceShip();
	~SpaceShip();

	//Member Functions
	void Update(const float& ar_DeltaTime) override;
};
