#pragma once
#include "MovementComponent.h"
#include "CollisionComponent.h"

class State
{
public:
	~State();

	//Member Functions
	virtual void Update(const float &ar_DeltaTime, const MovementComponent  *ar_Movement,
		 CollisionComponent *ar_Collision) const = 0;
};

