#include "SpaceShipNormalState.h"



SpaceShipNormalState::SpaceShipNormalState()
{
}


SpaceShipNormalState::~SpaceShipNormalState()
{
}

/*
 *
 */
void SpaceShipNormalState::Update(const float& ar_DeltaTime, const MovementComponent* ar_Movement,
	 CollisionComponent* ar_Collision) const
{
	ar_Movement->Update(ar_DeltaTime); //Update the kinematics equations

	//Update the position of the sprite
	ar_Collision->Update(ar_DeltaTime, ar_Movement->GetVelocity());
}


