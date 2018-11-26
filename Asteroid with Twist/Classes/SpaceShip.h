#pragma once
#include "GameEntities.h"

class SpaceShip :
	public GameEntities
{
public:
	//Constructors and Destructor
	SpaceShip();
	~SpaceShip();

	//Member Functions
	void Update(const float& ar_DeltaTime) override;
};
